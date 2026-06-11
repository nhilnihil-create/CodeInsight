#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
#include<unordered_map>
using namespace std;
//<DEFINE>
void Fast() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
}
void File() {
#ifndef ONLINE_JUDGE
	freopen("Input.txt", "r", stdin);
	freopen("Output.txt", "w", stdout);
#endif
}
#ifdef _MSC_VER
#include <intrin.h>
#define __builtin_popcount __popcnt
#ifdef _WIN64
#define __builtin_popcountll __popcnt64
#else
inline int __builtin_popcountll(__int64 a) {
	return __builtin_popcount((unsigned int)a) + __builtin_popcount(a >> 32);
}
#endif
#endif
using ll = long long;
using ull = unsigned long long;
#define mod 1000000007
ll gcd(ll a, ll b) {
	return!b ? a : gcd(b, a % b);
}
#define fix(n) cout << fixed << setprecision(n);
#define all(a) a.begin(), a.end()
#define skip continue
#define stop(n) return cout<<n,0
#define pi  acos(-1)
#define endl "\n"
//#define ceil(x,y) ((x+y-1)/y)
//sin(x*pi/180)
//alot of memset may cause TLE
#define TC int t;cin>>t;while(t--)
//</DEFINE>
int dx[] = { 0,0,-1,1,1,1,-1,-1 };
int dy[] = { 1,-1,0,0,1,-1,1,-1 };
ll n, slime[401];
ll res[401][401];
//<FUNCTIONS>
ll solve(int l = 1, int r = n ) {
	ll& mn = res[l][r];
	if (~mn)return mn;
	if (l == r)return 0;
	mn = 1e18;
	ll x, y;
	for (int i = l + 1; i <= r; i++) {
		mn = min(mn, solve(l, i - 1) + slime[i - 1] - slime[l - 1] + solve(i, r) + slime[r] - slime[i - 1]);
	}
	return mn;
}
//</FUNCTIONS>	
int main() {
	Fast();
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> slime[i], slime[i] += slime[i - 1];
	}
	memset(res, -1, sizeof(res));
	cout << solve();
}