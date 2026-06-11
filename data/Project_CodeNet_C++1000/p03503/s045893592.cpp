#include <bits/stdc++.h>
#define rep(i,n) for(ll i=0;i<(n);i++)
#define all(x) (x).begin(), (x).end()
using ll = long long;
using namespace std;
template <typename T>
using vec = std::vector<T>;

int main() {
    int N;
    cin >> N;
    vec<vec<int>> F(N,vec<int>(10));
    rep(i,N)rep(j,10) cin >> F[i][j];
    vec<vec<int>> P(N,vec<int>(11));
    rep(i,N)rep(j,11) cin >> P[i][j];

    ll ans = -1e9;
    rep(i,1<<10){
        if(i==0) continue;
        ll tmpans = 0;
        rep(f,N){
            int d = 0;
            rep(j,10){
                if(!(i&1<<j)) continue;
                if(F[f][j]) ++d;
            }
            tmpans += P[f][d];
        }
        ans = max(ans,tmpans);
    }
    cout << ans << endl;
}