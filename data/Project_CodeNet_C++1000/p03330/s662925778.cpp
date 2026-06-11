#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include <boost/multiprecision/cpp_int.hpp>
//typedef boost::multiprecision::cpp_int ll;
typedef long double dd;
#define i_7 (ll)(1E9+7)
//#define i_7 998244353
#define i_5 i_7-2
ll mod(ll a){
    ll c=a%i_7;
    if(c>=0)return c;
    return c+i_7;
}
typedef pair<ll,ll> l_l;
ll inf=(ll)1E16;
#define rep(i,l,r) for(ll i=l;i<=r;i++)
#define pb push_back
ll max(ll a,ll b){if(a<b)return b;else return a;}
ll min(ll a,ll b){if(a>b)return b;else return a;}
void Max(ll &pos,ll val){pos=max(pos,val);}//Max(dp[n],dp[n-1]);
void Min(ll &pos,ll val){pos=min(pos,val);}
void Add(ll &pos,ll val){pos=mod(pos+val);}
dd EPS=1E-9;
#define fastio ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

int main(){
    ll n,C;cin>>n>>C;
    ll d[C+1][C+1];
    rep(i,1,C)rep(j,1,C)cin>>d[i][j];
    ll c[n][n];
    rep(i,0,n-1)rep(j,0,n-1)cin>>c[i][j];
    ll hoge[3][C+1];
    rep(i,0,2)rep(j,1,C)hoge[i][j]=0;
    rep(i,0,n-1)rep(j,0,n-1){
        rep(k,1,C){
            hoge[(i+j)%3][k]+=d[c[i][j]][k];
        }
    }
    ll ans=inf;
    rep(i,1,C){
        rep(j,1,C){
            rep(k,1,C){
                if(i!=j && j!=k && k!=i){
                    ans=min(ans,hoge[0][i]+hoge[1][j]+hoge[2][k]);
                }
            }
        }
    }
    cout<<ans<<endl;
    return 0;
}
