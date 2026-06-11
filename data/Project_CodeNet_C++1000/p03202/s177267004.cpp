#include <iostream>
#include <string>
#include <cstdio>
#include <functional>
#include <algorithm>
#include <vector>
#include <stack>
#include <cmath>
#include <climits>
#include <bitset>
#include <array>
using namespace std;

struct Block
{
	int Num, Count;
	Block() { Num = Count = 0; }
	Block(int n, int c) { Num = n; Count = c; }
};

struct Integer
{
	stack<Block> blocks;
	stack<int> sum;
	int P;
	Integer(int n, int p) { blocks.emplace(0, n); sum.emplace(0); sum.emplace(n); P = p; }
	void Add(int c) { Push(Block(0, c)); }
	int Length() { return sum.top(); }
	void Take(int c)
	{
		Block b;
		while (Length() > c) b = Pop();
		if (Length() < c) Push(Block(b.Num, c - Length()));
	}
	bool Increment()
	{
		auto b = Pop();
		auto x = b.Num;
		auto n = b.Count;
		if (x == P - 1 && Length() == 0) return false;
		// y*m x*n => y*(m-1) (y+1)*1 0*n
		if (x == P - 1)
		{
			b = Pop();
			auto y = b.Num;
			auto m = b.Count;
			Push(Block(y, m - 1));
			Push(Block(y + 1, 1));
			Push(Block(0, n));
		}
		// x*n => x*(n-1) (x+1)*1
		else
		{
			Push(Block(x, n - 1));
			Push(Block(x + 1, 1));
		}
		return true;
	}
	Block Pop()
	{
		auto x = blocks.top(); blocks.pop();
		sum.pop();
		return x;
	}
	void Push(const Block& b)
	{
		if (b.Count == 0) return;
		auto p = b;
		if (Length() > 0 && blocks.top().Num == b.Num) p = Block(b.Num, b.Count + Pop().Count);
		blocks.emplace(p);
		sum.emplace(Length() + p.Count);
	}
};

int N;
vector<int> A;

bool check(int p)
{
	Integer S(A[0], p);
	for (size_t i = 1; i < N; i++)
	{
		auto a = A[i];
		if (a > S.Length()) S.Add(a - S.Length());
		else
		{
			S.Take(a);
			if (!S.Increment()) return false;
		}
	}
	return true;
}

int FirstBinary(int min, int max, function<bool(int)> pred)
{
	while (min < max)
	{
		auto mid = (min + max) / 2;
		if (pred(mid)) max = mid;
		else min = mid + 1;
	}
	return min;
}

int main()
{
	cin.tie(0);
	ios::sync_with_stdio(false);
	cin >> N;
	for (size_t i = 0; i < N; i++)
	{
		int x; cin >> x;
		A.push_back(x);
	}
	cout << FirstBinary(1, N, check) << endl;
    return 0;
}
