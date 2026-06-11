/*---Bismillahir Rahmanir Rahim---*/
#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <cstring>
#include <unordered_map>
#include <queue>
#define mod 998244353
#define int long long
#define ld long double
#define pb push_back
#define sz(x) (int)x.size()
#define ff first
#define ss second
#define pii pair<int, int>
using namespace std; 

map <int,int> cnt;
inline void solve()
{
	int m,n,ans=0;
	cin >> n >> m;
	for (int i=0;i<n;i++) {
		int  k; cin >> k;
		while (k--) {
			int  a; cin >> a ; 
			cnt[a]++;
		}
	}
	for (int i=1;i<=m;i++)
		if (cnt[i]==n) ans++;
	cout << ans << endl ; 
}

signed main()
{
	int t=1; // cin>>t;
	while(t--) solve();
	return 0;
}

/*
3 4
2 1 3
3 1 2 3
2 3 2

*/
