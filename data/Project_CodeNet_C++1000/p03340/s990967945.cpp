#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include <boost/multiprecision/cpp_ll.hpp>
//typedef boost::multiprecision::cpp_ll ll;
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
ll inf=(ll)1E18;
#define rep(i,l,r) for(ll i=l;i<=r;i++)
#define pb push_back
ll max(ll a,ll b){if(a<b)return b;else return a;}
ll min(ll a,ll b){if(a>b)return b;else return a;}
void Max(ll &pos,ll val){pos=max(pos,val);}//Max(dp[n],dp[n-1]);
void Min(ll &pos,ll val){pos=min(pos,val);}
void Add(ll &pos,ll val){pos=mod(pos+val);}
dd EPS=1E-9;
#define endl "\n"
#define fastio ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);



int main(){fastio
    ll n;cin>>n;
    ll a[n+1];rep(i,1,n)cin>>a[i];
    ll sum[21][n+3];    //2^iの桁で[0,j)の範囲に1が何個あるか
    rep(i,0,20){
        sum[i][0]=-1;
        sum[i][1]=0;
        sum[i][n+2]=inf;
    }
    rep(i,0,20){
        rep(j,2,n+1){
            if((a[j-1]>>i)&1){
                sum[i][j]=sum[i][j-1]+1;
            }else{
                sum[i][j]=sum[i][j-1];
            }
        }
    }
    ll ans=0;
    rep(i,1,n){
        ll mini=n+1;
        rep(j,0,20){
            ll l=i;
            ll r=n+2;
            while(r-l>1){
                ll mid=(l+r)/2;
                if(sum[j][mid]>=sum[j][i]+2){
                    r=mid;
                }else{
                    l=mid;
                }
            }
            mini=min(mini,r-i-1);
        }
        ans+=mini;
    }
    cout<<ans<<endl;
    
    
        
    return 0;
}



