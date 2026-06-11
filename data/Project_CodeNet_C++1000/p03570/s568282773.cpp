#include<iostream>
#include<string>
#include<cstdio>
#include<cstring>
#include<vector>
#include<cmath>
#include<algorithm>
#include<functional>
#include<iomanip>
#include<queue>
#include<deque>
#include<ciso646>
#include<random>
#include<map>
#include<set>
#include<complex>
#include<bitset>
#include<stack>
#include<unordered_map>
#include<utility>
#include<cassert>
using namespace std;

typedef long long ll;
typedef unsigned long long ul;
typedef unsigned int ui;
typedef long double ld;
const int inf=1e9+7;
const ll INF=1LL<<60 ;
const ll mod=1e9+7 ;
#define rep(i,n) for(int i=0;i<n;i++)
#define per(i,n) for(int i=n-1;i>=0;i--)
#define Rep(i,sta,n) for(int i=sta;i<n;i++)
#define rep1(i,n) for(int i=1;i<=n;i++)
#define per1(i,n) for(int i=n;i>=1;i--)
#define Rep1(i,sta,n) for(int i=sta;i<=n;i++)
typedef complex<ld> Point;
const ld eps = 1e-8;
const ld pi = acos(-1.0);
typedef pair<int, int> P;
typedef pair<ld, ld> LDP;
typedef pair<ll, ll> LP;
#define fr first
#define sc second
#define all(c) c.begin(),c.end()
#define pb push_back
#define debug(x)  cout << #x << " = " << (x) << endl;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
//#define int long long

void solve() {
	string s; cin >> s;
    int n = (int)s.size();
    vector<int> a(n + 1, 0);
    rep(i, n) {
        a[i + 1] = (a[i] ^ (1<<(s[i] - 'a')));
    }
    vector<int> x((1<<26), inf);
    vector<int> dp(n + 1, inf);
    dp[0] = 0;
    x[0] = 0;
    rep(i, n) {
        int y = (a[i + 1] ^ 0);
        chmin(dp[i + 1], x[y] + 1);
        chmin(x[a[i + 1]], dp[i + 1]);
        for(int bit = 0; bit < 26; ++bit) {
            int mask = (1<<bit);
            int y = (a[i + 1] ^ mask);
            chmin(dp[i + 1], x[y] + 1);
            chmin(x[a[i + 1]], dp[i + 1]);
        }
    }
    cout << dp[n] << endl;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	//cout << fixed << setprecision(10);
	//init();
	solve();
	//cout << "finish" << endl;
    return 0;
}