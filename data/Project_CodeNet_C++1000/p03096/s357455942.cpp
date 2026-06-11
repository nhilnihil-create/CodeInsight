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
const ll mod = 1000000007;
const ll INF = mod * mod;
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
typedef vector<int> vec;
typedef vector<string> svec;
#define fr first
#define sc second
#define all(c) c.begin(),c.end()
#define pb push_back
//#define int long long

int n;
vector<int> places[200200];
ll dp[200200];

void add(ll &a, ll b) {a += b; if(a >= mod) a -= mod;}

void solve() {
    cin >> n;
    vector<int> c(n);
    rep(i, n) {
        cin >> c[i];
        places[c[i]].push_back(i);
    }
    dp[0] = 1LL;
    for(int i = 1; i <= n; i++) {
        add(dp[i], dp[i - 1]);

        int color = c[i - 1];
        int it = lower_bound(all(places[color]), i - 1) - places[color].begin();
        if(it > 0) {
            int j = places[color][it - 1];
            if((i - 1) - j > 1) add(dp[i], dp[j + 1]);
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