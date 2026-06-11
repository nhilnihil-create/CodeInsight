#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <tuple>
#include <iomanip>
#include <cmath>
#include <queue>
#include <deque>
#include <stack>
#include <stdio.h>
#include <cstring>
//#pragma GCC optimize("Ofast")
//#pragma GCC target("avx,avx2")
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long double ld;
typedef long long ll;
typedef double db;
#define endl '\n'
#define pb push_back
#define pii pair<ll, ll>
#define ff first
#define ss second
#define sz(x) (ll)(x).size()
#define optimize1() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#pragma warning(disable:4996)

using namespace std;
const int MX = 2e5 + 1e3;

int a[MX], sp[MX];
int n;

bool check(int x)
{
	int i;
	map<int, int>mp;

	for (i = 1; i <= n; i++)
	{
		if (a[i] <= a[i - 1])
		{
			while (!mp.empty())
			{
				int t = mp.rbegin()->first;
				if (t > a[i])
					mp.erase(t);
				else
					break;
			}
			int j = a[i];
			while (mp[j] + 1 == x) {
				mp.erase(j);
				j--;
			}

			if (j == 0)
				return 0;
			mp[j]++;
		}
	}
	return 1;
}

signed main() {
    optimize1();

	cin >> n;
	bool ppp = 0;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
		if (a[i] <= a[i - 1])ppp = 1;
	}

	if (ppp == 0) {
		cout << 1 << endl;
		return 0;
	}

	int l = 2, r = n;
	while (l < r)
	{
		int m = (l + r) / 2;
		if (check(m))
			r = m;
		else 
			l = m + 1;
	}
	cout << l << endl;
	return 0;
}