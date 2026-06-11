//#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define pp pair<int,int>
#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
#define ld long double
#define al(a) (a).begin(),(a).end()
#define mk make_pair
#define check cout<<"?"<<endl;

ll MOD=1000000007;
ll mod=998244353;
int inf=1000001000;
ll INF=1e18+5;

int main(){
    ll n,k,ans=1e18*4; cin>>n>>k;
    vector<pair<ll,ll>> d(n);
    rep(i,n){
        ll x,y; cin>>x>>y;
        d[i]=mk(x,y);
    }
    ll xi,xj,yi,yj,x,y;
    for(ll pi=0;pi<n-1;pi++)for(ll pj=pi+1;pj<n;pj++){
        for(ll qi=0;qi<n-1;qi++)for(ll qj=qi+1;qj<n;qj++){
            tie(xi,ignore)=d[pi]; tie(xj,ignore)=d[pj];
            tie(ignore,yi)=d[qi]; tie(ignore,yj)=d[qj];
            if(xi>xj) swap(xi,xj);
            if(yi>yj) swap(yi,yj);
            ll cnt=0;
            rep(i,n){
                tie(x,y)=d[i];
                if(xi<=x && x<=xj && yi<=y && y<=yj) cnt++;
            }
            if(cnt>=k) ans=min(ans,(xj-xi)*(yj-yi));
        } 
    }
    cout<<ans<<endl;
}