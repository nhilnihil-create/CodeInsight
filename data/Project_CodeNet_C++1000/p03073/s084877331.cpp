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

map <char,int> cnt;
inline void solve()
{
	string s; int l=0,r=0;
	cin >> s; 
	for (int i=0;i<sz(s);i++) {
		if (i&1){
			if (s[i] == '0') l++; //000
		}
		else {
			if (s[i]=='1') l++;
		}
	}
	for (int i=0;i<sz(s);i++) {
		if (i&1){
			if (s[i] == '1') r++;
		}
		else {
			if (s[i]=='0') r++;
		}
	}
	
	cout << min(l,r) << endl;
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
