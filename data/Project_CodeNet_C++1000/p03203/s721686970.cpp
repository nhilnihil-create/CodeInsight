
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define i_7 (ll)(1E9+7)
#define i_5 (ll)(1E9+5)
//#define i_7 998244353
//#define i_5 998244351
ll mod(ll a){
    ll c=a%i_7;
    if(c>=0)return c;
    else return c+i_7;
}
typedef pair<ll,ll> l_l;
ll inf=(ll)1E17;
#define rep(i,l,r) for(ll i=l;i<=r;i++)
#define pb push_back
ll max(ll a,ll b){if(a<b)return b;else return a;}
ll min(ll a,ll b){if(a>b)return b;else return a;}
void Max(ll &pos,ll val){pos=max(pos,val);}//Max(dp[n],dp[n-1]);
void Min(ll &pos,ll val){pos=min(pos,val);}
void Add(ll &pos,ll val){pos=mod(pos+val);}
long double EPS=1E-8;
////////////////////////////////////////


int main(){
    ll h,w,n;cin>>h>>w>>n;
    ll ob[n][2];rep(i,0,n-1)rep(j,0,1){cin>>ob[i][j];ob[i][j]--;}
    ll u[h];rep(i,0,h-1)u[i]=inf;
    rep(i,0,n-1){
        Min(u[ob[i][0]],ob[i][1]);
    }
    //rep(i,0,n-1)cout<<u[i]<<" ";cout<<endl;
    if(h==1){
        cout<<1<<endl;return 0;
    }
    if(u[1]==0){
        cout<<1;return 0;
    }
    ll maxy=0;
    rep(i,1,h-2){
        if(u[i]!=maxy+1)maxy++;
        if(u[i+1]<=maxy){
            cout<<i+1<<endl;return 0;
        }
    }
    cout<<h<<endl;
    
    return 0;
}

