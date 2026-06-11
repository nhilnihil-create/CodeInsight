#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define F first
#define S second
#define pii pair<int, int>
#define eb emplace_back
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rep3(i, l, n) for (int i = l; i < (n); ++i)
#define sz(v) (int)v.size()
#define inf (int)(1e9+7)
#define abs(x) (x >= 0 ? x : -(x))
template<typename T1, typename T2> inline void chmin(T1 &a, T2 b) { if (a > b) a = b; }
template<typename T1, typename T2> inline void chmax(T1 &a, T2 b) { if (a < b) a = b; }
template<typename T> inline T gcd(T a, T b) { if (b == 0) return a; return gcd(b, a % b); }






int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    
    
    
    int n, z, w;
    cin >> n >> z >> w;
    
    vector<int> a(n);
    rep(i, n) cin >> a[i];
    
    // xさん結局最後2枚のどっちかになる
    if (n == 1) cout << abs(a[0] - w) << endl;
    else cout << max(abs(a[n - 2] - a[n - 1]), abs(a[n - 1] - w)) << endl;
}


