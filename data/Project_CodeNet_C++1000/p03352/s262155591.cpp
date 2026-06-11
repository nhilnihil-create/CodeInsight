#include <bits/stdc++.h>
using namespace std;
#define _GLIBCXX_DEBUG
#define rep(i,n) for(int i = 0; i < (n); ++i)
#define ll long long
#define P pair<ll,ll>
#define all(v) (v).begin(),(v).end()

const ll mod = 1e9+7;
const ll INF = 1e18;
const double pi = acos(-1.0);

ll p(ll a,ll b){
    if(b==0) return 1;
    ll tmp=1;
    rep(i,b){
        tmp*=a;
    }
    return tmp;
}

int main(void)
{
    ll x; cin>>x;
    ll ans=-1;
    for(int i=1;i<=1000;i++){
        for(int j=2;j<=10;j++){
            if(p(i,j) <= x){
                ans=max(ans,p(i,j));
            }
        }
    }
    cout<<ans<<endl;
    return 0;
}