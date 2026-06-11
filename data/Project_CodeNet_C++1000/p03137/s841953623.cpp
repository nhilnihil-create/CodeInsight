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
    ll n,m; cin>>n>>m;
    vector<ll> x(m,0);
    rep(i,m) cin>>x[i];
    if(n>=m) cout<<0<<endl;
    else{
        sort(al(x));
        vector<ll> d(m-1,0);
        rep(i,m-1) d[i]=x[i+1]-x[i];
        sort(al(d));
        ll ans=0;
        rep(i,m-n) ans+=d[i];
        cout<<ans<<endl; 
    }
}