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

struct block
{
	const int num, count;
	block() : num(0), count(0) { }
	block(int n, int c) : num(n), count(c) { }
};

class integer
{
	stack<block> blocks;
	stack<int> sum;
	const int P;
	block pop()
	{
		auto x = blocks.top(); blocks.pop();
		sum.pop();
		return x;
	}
	void push(const block& b)
	{
		if (b.count == 0) return;
		auto p = length() > 0 && blocks.top().num == b.num ? block(b.num, b.count + pop().count) : b;
		blocks.emplace(p);
		sum.emplace(length() + p.count);
	}
public:
	integer(int n, int p) : P(p) { blocks.emplace(0, n); sum.emplace(0); sum.emplace(n); }
	void add(int c) { push(block(0, c)); }
	int length() const { return sum.top(); }
	void take(int c)
	{
		auto last = -1;
		while (length() > c) last = pop().num;
		if (length() < c) push(block(last, c - length()));
	}
	bool incr()
	{
		auto b = pop();
		auto x = b.num;
		auto n = b.count;
		if (x == P - 1 && length() == 0) return false;
		// y*m x*n => y*(m-1) (y+1)*1 0*n
		if (x == P - 1)
		{
			auto c = pop();
			auto y = c.num;
			auto m = c.count;
			push(block(y, m - 1));
			push(block(y + 1, 1));
			push(block(0, n));
		}
		// x*n => x*(n-1) (x+1)*1
		else
		{
			push(block(x, n - 1));
			push(block(x + 1, 1));
		}
		return true;
	}
};

int N;
vector<int> A;

bool check(int p)
{
	integer S(A[0], p);
	for (size_t i = 1; i < N; i++)
	{
		auto a = A[i];
		if (a > S.length()) S.add(a - S.length());
		else
		{
			S.take(a);
			if (!S.incr()) return false;
		}
	}
	return true;
}

int first_binary(int min, int max, function<bool(int)> pred)
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
	cout << first_binary(1, N, check) << endl;
    return 0;
}
