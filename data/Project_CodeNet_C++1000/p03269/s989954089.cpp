#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#  include <intrin.h>
#  define __builtin_popcount __popcnt
#endif

#define _USE_MATH_DEFINES

#include <stdio.h>
#include <iostream>
#include <vector>
#include <unordered_map>
#include <stack>
#include <list>
#include <math.h>
#include <iterator>
#include <map>
#include <iomanip>
#include <functional>
#include <string>
#include <algorithm>
#include <queue>
#include <random>
#include <set>

using namespace std;

template<class T> ostream& operator<<(ostream& os, const vector<T>& v) {
	for (auto i = begin(v); i != end(v); i++) os << *i << (i == end(v) - 1 ? "" : " "); return os;
}
template<class T> istream& operator>>(istream& is, vector<T>& v) {
	for (auto i = begin(v); i != end(v); i++) is >> *i; return is;
}

#define MOD 1000000007
#define inf 2000000000

set<int> edg[101000];

int main() {

#if defined(_DEBUG) 
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int L;
	cin >> L;

	vector<int> bits;
	vector<int> pwrs;
	int LL = L;
	int pw = 1;
	while (LL > 0)
	{
		bits.push_back(LL % 2);
		LL /= 2;
		pwrs.push_back(pw);
		pw *= 2;
	}
	reverse(bits.begin(), bits.end());
	reverse(pwrs.begin(), pwrs.end());

	bool compress = false;
	

	vector<vector<pair<int,int>>> edges(bits.size() + 1);
	if (bits.size() == 20)
	{
		compress = true;
	}
	
	for (int i = 1; i < edges.size(); i++)
		edges[i - 1].push_back({ i,0 });

	int acc = pwrs[0];
	for (int i = 1; i + 1 < edges.size(); i++)
	{
		if (bits[i])
		{
			edges[0].push_back({ i + 1, acc });
			acc += pwrs[i];
		}
	}
	//edges[0].push_back({ edges.size() - 1, acc });

	for (int i = 1; i + 1 < edges.size(); i++)
	{
		edges[i].push_back({ i + 1, pwrs[i] });
	}

	if (compress)
	{
		for (int i = 0; i + 1 < edges.size(); i++)
		{
			auto new_vec = edges[i];
			new_vec.clear();
			for (auto x : edges[i])
			{
				if (x.first == 19)
				{
					new_vec.push_back(x);
					new_vec.push_back({ x.first, x.second + 1 });
				}
				else
				{
					if (x.first == 20)
						x.first = 19;
					new_vec.push_back(x);
				}
			}

			edges[i] = new_vec;
		}


		edges.pop_back();
		edges.back().clear();
	}


	int total = 0;
	for (auto x : edges)
		total += x.size();

	cout << edges.size() << " " << total << "\n";
	for (int i = 0; i < edges.size(); i++)
	{
		for (auto y: edges[i])
		{
			cout << i + 1 << " " << y.first + 1 << " " << y.second << "\n";
		}
	}

	return 0;
}
