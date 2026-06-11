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

#include <bits/stdc++.h>
#define rep(i,a,n) for(ll i = a;i < n;i++)
typedef long long ll;
using namespace std;

int main(){ 
    ll h,w;
    cin >> h >> w;

    char a[h][w] = {};
    ll dist[h][w] = {};

    rep(i,0,h){
        rep(j,0,w){
            cin >> a[i][j];
            if(a[i][j] == '.') dist[i][j] = LINF;
            else dist[i][j] = 0;
        }
    }

    rep(i,0,h){ //左から
        rep(j,1,w){
            dist[i][j] = min(dist[i][j],dist[i][j-1]+1);
        }
    }

    rep(i,0,h){ //右から
        rep(k,1,w){
            ll j = w-k-1;
            dist[i][j] = min(dist[i][j],dist[i][j+1]+1);
        }
    }

    rep(i,1,h){ //上から
        rep(j,0,w){
            dist[i][j] = min(dist[i][j],dist[i-1][j]+1);
        }
    }

    rep(k,1,h){ //下から
        rep(j,0,w){
            ll i = h-k-1;
            dist[i][j] = min(dist[i][j],dist[i+1][j]+1);
        }
    }

    ll ans = 0;
    rep(i,0,h){
        rep(j,0,w){
            ans = max(ans,dist[i][j]);
        }
    }

    cout << ans << endl;
}
