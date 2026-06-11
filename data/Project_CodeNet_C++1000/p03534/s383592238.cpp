#ifdef LOCAL
#include <cstdio>
#include <vector>
#include <algorithm>
#include <iostream>
#include <cstring>
#else
#include <bits/stdc++.h>
#endif
using namespace std ;

typedef long long ll ;
#define rep(i , n ) for ( int i =0; i < n ; i++)
#define _sort(arg) sort(begin(arg), end(arg))
#define MOD 1000000007
#define pb push_back
#define DEBUG(x) cout << #x << ": " << x << endl;

/*
__attribute__((constructor))
void initial()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);
}
*/

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	string s;
	
	cin >> s;

	int len = s.size();

	int a[3] = {0};

	rep(i, len)
	{
		a[s[i] - 'a']++;
	}

	sort(a, a+3);

	if (a[2] - a[0] <=1)
	{
		cout << "YES" << endl;
	}
	else
	{
		cout << "NO" << endl;
	}
	
	return 0;
}
