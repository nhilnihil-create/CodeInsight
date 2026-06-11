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
int n;
int main() {
	PRE;
	int n;
	cin >> n;
	map<int, int> ma;
	for (int i = 1;i <= n;i++)
	{
		cin >> lst[i];
		ma[lst[i]]++;
	}
	ll res = 0;
	for (auto i = ma.begin();i != ma.end();i++)
	{
		if (i->second == i->first) continue;
		if (i->second < i->first) res += i->second;
		else
		{
			res += (i->second - i->first);
		}
	}
	cout << res;


}

