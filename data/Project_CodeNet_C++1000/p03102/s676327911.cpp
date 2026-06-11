#include <bits/stdc++.h>
using namespace std;

#define rep(i,n) for(int i = 0; i < (n); ++i)
#define ll long long
#define P pair<ll,ll>
#define all(v) v.begin(),v.end()
const ll mod = 1e9+7;
const ll INF = 1e18;
const double pi = acos(-1.0);

int main(void)
{
   ll n,m,c; cin>>n>>m>>c;
   vector<ll> b(m);
   vector<vector<ll>> a(n,vector<ll>(m));
   rep(i,m) cin>>b[i];
   rep(i,n)rep(j,m) cin>>a[i][j];
   ll ans=0;
   rep(i,n){
       ll sum=0;
        rep(j,m){
            sum+=a[i][j]*b[j];
        }
        if(sum+c>0) ++ans;
    }
    cout<<ans<<endl;
}