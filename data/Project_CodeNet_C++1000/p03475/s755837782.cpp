#include "bits/stdc++.h"
#define rep(i,n) for(int i = 0; i < (n); ++i)
using namespace std;
typedef long long int ll;
typedef pair<ll, ll> P;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    vector<ll> c(n-1), s(n-1), f(n-1);
    rep(i,n-1) cin >> c[i] >> s[i] >> f[i];
    rep(i,n-1){
        ll t = s[i];
        for(int j = i; j < n-1; ++j){
            ll nex = max(t - s[j], 0LL) / f[j] * f[j] + s[j];
            if(t > nex) nex += f[j];
            t = nex + c[j];
        }
        std::cout << t << endl;
    }
    std::cout << 0 << endl;
    return 0;
}
