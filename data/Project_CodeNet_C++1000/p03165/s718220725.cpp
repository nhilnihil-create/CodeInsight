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
#define pi  acos(-1)
#define endl "\n"
//#define ceil(x,y) ((x+y-1)/y)
//sin(x*pi/180)
//be careful from the multiplication while using this define 
//alot of memset may cause TLE
#define TC int t$$t$;cin>>t$$t$;while(t$$t$--)
//</DEFINE>
int dx[] = { 0,0,-1,1,1,1,-1,-1 };
int dy[] = { 1,-1,0,0,1,-1,1,-1 };
int send, tend;
string s, t;
int res[3000][3000];
//<FUNCTIONS>	
int solve(int sidx = 0, int tidx = 0) {
	if (sidx == send || tidx == tend)return 0;
	int& mx = res[sidx][tidx];
	if (~mx)return mx;
	if (s[sidx] == t[tidx])return mx = solve(sidx + 1, tidx + 1) + 1;
	return mx = max(solve(sidx + 1, tidx), solve(sidx, tidx + 1));
}
string build(int sidx = 0, int tidx = 0) {
	if (sidx == send || tidx == tend)return "";
	if (s[sidx] == t[tidx])return s[sidx] + build(sidx + 1, tidx + 1);
	if (solve(sidx + 1, tidx) == res[sidx][tidx])return build(sidx + 1, tidx);
	else return build(sidx, tidx + 1);
}
//</FUNCTIONS>	
int main() {
	Fast();
	cin >> s >> t;
	send = s.size(), tend = t.size();
	memset(res, -1, sizeof(res));
	solve();
	cout << build() << endl;
}