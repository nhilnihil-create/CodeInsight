#include<iostream>
#include<string>
#include<algorithm>
#include<cstdio>
#include<memory.h>
#include<map>
#include<vector>
#define PRE std::ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
const int Max = 1e6 + 5;
const int Mod = 1e9 + 7;
int lst[Max];
const int max_n = 1e4 + 100;
struct oper {
	int i, j, x;
};
struct nde {
	int val, id;
	bool operator<(nde& n2) {
		if (val % id == 0)return true;
		if (n2.val % n2.id == 0)return true;
		int t1 = id - val % id;
		int t2 = n2.id - n2.val % n2.id;
		if (t1 != t2)return t1 < t2;
		return val > n2.val;
	}
}a[max_n];

int main()
{
	ll x, y;
	cin >> x >> y;
	ll ans = y / x;
	int f = 0;
	while (ans)
	{
		++f;
		ans /= 2;
	}
	cout << f;
}

