#include "bits/stdc++.h"
#define rep(i,n) for(int i = 0; i < (n); ++i)
using namespace std;
typedef long long int ll;
typedef pair<int, vector<ll>> P;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n, m;
    cin >> n >> m;
    vector<ll> x(m);
    rep(i,m) cin >> x[i];
    if(n >= m){
        cout << 0 << endl;
        return 0;
    }
    sort(x.begin(), x.end());
    vector<ll> dis(m-1);
    rep(i,m-1){
        dis[i] = x[i+1] - x[i];
    }
    sort(dis.begin(), dis.end());
    ll ans = 0;
    rep(i,m-n){
        ans += dis[i];
    }
    cout << ans << endl;
    return 0;
}
