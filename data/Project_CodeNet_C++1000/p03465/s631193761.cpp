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
using Graph = vector<vector<int> >;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
//#define int long long

const int MAX = 4000400;
//vector<bool> は bitset<N> で定数倍高速化可能(64倍) (N = 2000 で N^3も通るくらい速い)

void solve() {
	int n; cin >> n;
    vector<int> a(n);
    int sum = 0;
    //部分集合とその補集合を考えたとき、うまいこと1対1対応があるので、大きい方半分の最小値
    rep(i, n) {
        cin >> a[i];
        sum += a[i];
    }
    //ナップサックのような部分和でO(N * NA)
    //配列の使い回しが可能
    bitset<MAX> dp;
    dp[0] = 1;
    rep(i, n) {
        dp |= (dp << a[i]);
    }
    ll res;
    for(res = (sum + 1) / 2; res < MAX; ++res) {
        if(dp[res]) break;
    }
    cout << res << endl;
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