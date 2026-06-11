#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll,ll> P;
typedef pair<P,ll> PLL;
typedef pair<P,P> PP;
typedef vector<ll> VECLL;
typedef vector<P> VECP;
typedef priority_queue<P,VECP,greater<P> > PQP;
typedef priority_queue<ll, VECLL, greater<ll> > PQll;

#define rep(i,a,n) for(ll i = a;i < n;i++)   
#define rrep(i,a,n) for(ll i = n; i >= a;i--)
#define index_check(i,n) if(i > n-1 || i < 0) continue; 
#define LINF (ll)1e18
#define INF (int)1e9
#define fs first
#define sc second

int main(){
    ll h,w;
    cin >> h >> w;
    ll d[10][10];
    rep(i,0,10) rep(j,0,10){
        cin >> d[i][j];
    }

    rep(k,0,10){
        rep(i,0,10){
            rep(j,0,10){
                d[i][j] = min(d[i][j],d[i][k] + d[k][j]);
            }
        }
    }

    ll ans = 0;
    rep(i,0,h){
        rep(j,0,w){
            ll a;
            cin >> a;
            if(a != -1) ans += d[a][1];
        }
    }

    cout << ans << endl;

    

    return 0;
}
