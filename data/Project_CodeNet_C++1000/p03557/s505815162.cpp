#include <bits/stdc++.h>
#define repp(i,l,r)for(long long i=(l);i<(r);i++)
#define rep(i,n) for (long long i = 0; i < (n); ++i)
#define per(i,n) for (long long i = (n); i >= 0; --i)
const int INF = 1 << 30;//int max
const long long int MOD = 1000000007;
using namespace std;
using ll = long long;
using P = pair<int,int>;
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
//ミョ(-ω- ?)
int main() {
    ll n;
    cin >> n;
    vector<ll> a(n,0);rep(i,n)cin >> a[i];sort(a.begin(),a.end());
    vector<ll> b(n,0);rep(i,n)cin >> b[i];sort(b.begin(),b.end());
    vector<ll> c(n,0);rep(i,n)cin >> c[i];sort(c.begin(),c.end());
    ll res = 0;
    rep(j,n){
        res += (lower_bound(a.begin(),a.end(),b[j]) - a.begin()) * (c.end() - upper_bound(c.begin(),c.end(),b[j]));
    }
    cout << res << endl;
    return 0;
}