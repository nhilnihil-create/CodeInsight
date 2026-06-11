#include<iostream>
#include<string>
#include<cstdio>
#include<vector>
#include<cmath>
#include<algorithm>
#include<functional>
#include<iomanip>
#include<queue>
#include<ciso646>
#include<random>
#include<map>
#include<set>
#include<complex>
#include<bitset>
using namespace std;
typedef long long ll;
typedef unsigned int ui;
const ll MOD = 1000000007;
const ll INF = (ll)1000000007 * 1000000007;
typedef pair<int, int> P;
#define stop char nyaa;cin>>nyaa;
#define rep(i,n) for(int i=0;i<n;i++)
#define per(i,n) for(int i=n-1;i>=0;i--)
#define Rep(i,sta,n) for(int i=sta;i<n;i++)
#define rep1(i,n) for(int i=1;i<=n;i++)
#define per1(i,n) for(int i=n;i>=1;i--)
#define Rep1(i,sta,n) for(int i=sta;i<=n;i++)
typedef long double ld;
typedef complex<ld> Point;
const ld eps = 1e-11;
const ld pi = acos(-1.0);
typedef pair<ll, ll> LP;
typedef pair<ld, ld> LDP;
int sum[200000];
int dp[1 << 26];
int main(){
	fill(dp, dp + (1 << 26), (int)MOD);
	string s; cin >> s; int n = s.length();
	int las = 0;
	rep(i, n) {
		int t = s[i] - 'a';
		las ^= (1 << t);
		sum[i] = las;
	}
	fill(dp, dp + n, (int)MOD);
	dp[0] = 1;
	rep(i, 26) {
		dp[1 << i] = 1;
	}
	rep(i, n) {
		int x = sum[i];
		rep(j, 26) {
			int y = x ^ (1 << j);
			dp[y] = min(dp[y], dp[x] + 1);
		}
	}
	cout << dp[las] << endl;
	return 0;
}