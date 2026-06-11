#include <bits/stdc++.h>
#define repp(i,l,r)for(long long i=(l);i<(r);i++)
#define rep(i,n) for (long long i = 0; i < (n); ++i)
#define per(i,n) for (long long i = (n); i >= 0; --i)
const int INF = 2147483647;//int max
const long long int MOD = 1000000007;
using namespace std;
using ll = long long;
using P = pair<int,int>;
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
//ミョ(-ω- ?)
int main() {
    ll n;
    string s;
    cin >> n >> s;
    vector<pair<ll,ll>> vp(n+1,{0,0});
    repp(i,1,n+1){
        vp[i] = vp[i-1];
        if(s[i-1] == '#')vp[i].first++;
        else vp[i].second++;
    }
    ll res = LONG_LONG_MAX;
    repp(i,1,n+1)res = min(res, vp[i-1].first + (vp[n].second - vp[i].second));
    cout << res << endl;
    return 0;
}