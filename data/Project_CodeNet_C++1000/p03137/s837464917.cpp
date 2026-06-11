#include <bits/stdc++.h>
#define rep(i,n) for (long long i = 0; i < (n); ++i)
const int INF = 2147483647;//int max
const long long int MOD = 1000000007;
using namespace std;
using ll = long long;
using P = pair<int,int>;
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
//ミョ(-ω- ?)
int main() {
    ll n,m;
    cin >> n >> m;
    vector<ll> a(m,0);
    rep(i,m)cin >> a[i];
    sort(a.begin(),a.end());
    vector<ll> diff;
    rep(i,m-1)diff.push_back(a[i+1] - a[i]);
    sort(diff.begin(),diff.end(),greater<ll>());
    ll res = a.back() - a.front();
    for (ll i = 0; i < min((ll)diff.size(), n-1); ++i) res -= diff[i];
    cout << res << endl;
    return 0;
}