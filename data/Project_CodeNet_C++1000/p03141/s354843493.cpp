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
    ll n,ans=0; cin>>n;
    vector<pair<ll,ll>> q(n);
    rep(i,n){
        ll a,b; cin>>a>>b;
        q[i]=mk(a+b,b);
    }
    sort(al(q)); reverse(al(q));
    rep(i,n){
        ans-=q[i].second;
        if(i%2==0) ans+=q[i].first;
    }
    cout<<ans<<endl;
}