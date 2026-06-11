#include <bits/stdc++.h>
#define rep(a,n) for (ll a = 0; a < (n); ++a)
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;
typedef vector<vector<ll> > Graph;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const ll INF = 1e18;

int f[110];
int p[110][15];

int main(){
    int n;
    cin >> n;
    rep(i,n){
        int s = 0;
        rep(j,10){
            bool x;
            cin >> x;
            if(x)s=(s<<1)|1;
            else s=s<<1;
        }
        f[i]=s;
    }
    ll ans = -INF;
    rep(i,n){
        rep(j,11){
            cin >> p[i][j];
        }
    }
    for (int bit =1;bit<(1<<10);bit++){
        ll tmp = 0;
        rep(i,n){
            int now = bit&f[i];
            int cnt = __builtin_popcount(now);
            tmp += p[i][cnt];
        }
        chmax(ans,tmp);
    }
    cout << ans << endl;

    return 0;
}

