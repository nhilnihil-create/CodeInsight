
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
////////////////////////////

#define N 10000
bool check(vector<ll>v,ll sum){
    //for(auto x:v)cout<<x<<" ";cout<<endl;
    //cout<<sum<<endl;
    ll n=v.size();
    bool dp[n+1][2*N];
    memset(dp,false,sizeof(dp));
    dp[0][N]=1;
    rep(i,0,n-1){
        rep(j,0,2*N-1){
            if(j-v[i]>=0)dp[i+1][j]|=dp[i][j-v[i]];
            if(j+v[i]<=2*N-1)dp[i+1][j]|=dp[i][j+v[i]];
        }
    }
    /*
    rep(i,0,n){
        rep(j,0,2*N-1){
            cout<<dp[i][j]<<" ";
        }cout<<endl;
    }*/
    if(dp[n][N+sum])return true;
    return false;
}



int main(){fastio
    string s;cin>>s;
    ll n;n=s.size();
    ll c=0;
    rep(i,0,n-1){
        if(s[i]=='F')c++;
        else break;
    }
    vector<ll>a,b;
    bool f=true;
    //cout<<c<<endl;
    rep(i,c+1,n-1){
        ll k=0;
        while(i<=n-1&&s[i]=='F'){
            k++;i++;
        }
        if(f)b.pb(k);
        else a.pb(k);
        f=1-f;
    }
    //for(auto x:a)cout<<x<<" ";cout<<endl;
    //for(auto x:b)cout<<x<<" ";cout<<endl;
    
    ll x,y;cin>>x>>y;
    x-=c;
    if(!check(a,x)){
        cout<<"No"<<endl;
    }else if(!check(b,y)){
        cout<<"No";
    }else{
        cout<<"Yes"<<endl;
    }
    
    
    
    return 0;
}
