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
    ll n,m,ans=0; cin>>n>>m;
    vector<pair<ll,ll>> e(n);
    rep(i,n){
        ll a,b; cin>>a>>b;
        e[i]=mk(a,b);
    }
    sort(al(e));
    rep(i,n){
        if(m>e[i].second){
            ans+=e[i].first*e[i].second;
            m-=e[i].second;
        }
        else{
            ans+=e[i].first*m;
            break;
        }
    }
    cout<<ans<<endl;
}