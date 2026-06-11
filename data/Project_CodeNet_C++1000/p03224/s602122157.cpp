#define _CRT_SECURE_NO_WARNINGS
#define forn(i, a, n) for(ll i = a; i < n; i++)

#include<stdio.h>
#include<iostream>
#include<vector>
#include<sstream>
#include<algorithm>
#include<limits.h>
#include<stack>
#include<queue>
#include<set>
//#pragma comment(linker, "/STACK:12822822 ")

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pll;
const ll mod = 1e9 + 7;
const ll power = 17;
const ll inf = 9223372036854775807LL;

ll s[1000][1000];
ll n;
bool used[1000];
ll t = 1;

void dfs(ll v, ll co)
{
	used[v] = true;
	forn(i, 0, co)
	{
		if (v == i)
			continue;
		if (s[v][i] == 0)
		{
			s[v][i] = t;
			s[i][v] = t;
			t++;
		}
		if (used[i])
			continue;
		dfs(i, co);
	}
}

void adskaya_drochilna(ll co)
{
	forn(i, 0, co)
	{
		cout << co - 1 << ' ';
		forn(j, 0, co)
		{
			if (i == j)
				continue;
			cout << s[i][j] << ' ';
		}
		cout << endl;
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	/*
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	*/


	cin >> n;
	forn(i, 0, n+5)
	{
		if (i * (i - 1) == 2 * n)
		{
			dfs(0, i);
			if (t > n + 1)
				break;
			cout << "Yes" << endl;
			cout << i << endl;
			adskaya_drochilna(i);
			return 0;
		}
	}
	cout << "No";

	return 0;
}
