#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

// chmax, chmin
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

int main() {
    ll N,M;
    cin >> N >> M;
    vector<ll> x(N),y(N),z(N),xm(N),ym(N),zm(N);
    for ( ll i = 0; i < N; ++i){
        cin >> x[i] >> y[i] >> z[i];
        xm[i] = -x[i]; ym[i] = -y[i]; zm[i] = -z[i];
    }
    
    vector<ll> a(N),b(N),c(N);
    ll ans = -1e+15;
    for ( int bit = 0; bit < (1<<3); ++bit){
        a = x; b = y; c = z;
        if ( bit & (1<<0) ) a = xm;
        if ( bit & (1<<1) ) b = ym;
        if ( bit & (1<<2) ) c = zm;
        
        vector<ll> xyz(N);
        for ( ll i = 0; i < N; ++i){
            xyz[i] = a[i] + b[i] + c[i];
        }
        sort(xyz.begin(),xyz.end());
        reverse(xyz.begin(),xyz.end());
        ll sum = 0;
        for ( int i = 0; i < M; ++i){
            sum += xyz[i];
        }
        chmax(ans,sum);
    }
    
    cout << ans << endl;
    
    return 0;
}
