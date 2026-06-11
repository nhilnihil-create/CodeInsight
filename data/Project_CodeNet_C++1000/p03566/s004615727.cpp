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

struct train{ ll l,r,v;};

int main(){
    ll n;cin>>n;
    train T[n+2];
    ll t[n],v[n];
    ll sum=0;
    rep(i,0,n-1){
        cin>>t[i];
        T[i].l=sum;
        sum+=t[i];
        T[i].r=sum;
    }
    rep(i,0,n-1){
        cin>>v[i];
        T[i].v=v[i];
    }
    T[n].r=0;T[n].l=0;T[n].v=0;
    T[n+1].r=sum;T[n+1].l=sum;T[n+1].v=0;
    double mini[2*(sum+1)];fill(mini,mini+2*(sum+1),10000000);
    ll l,r;
    rep(i,0,n+1){
        l=T[i].l;r=T[i].r;
        rep(j,0,sum*2){
            if(j<=l*2){
                mini[j]=min(mini[j],(double)T[i].v+(double)(2*l-j)/2);
            }else if(j>=2*r){
                mini[j]=min(mini[j],(double)T[i].v+(double)(j-r*2)/2);
            }else{
                mini[j]=min(mini[j],(double)T[i].v);
            }
        }
    }
    double total=0;
    rep(i,0,sum-1){
        if(fabs(mini[i*2]-mini[i*2+2])<0.000001){
            if(fabs(mini[i*2+1]-mini[i*2])<0.0000001){
                total+=mini[i*2];
                //cout<<mini[i*2]<<endl;
            }else{
                total+=(mini[i*2]+0.25);
                //cout<<(mini[i*2]+0.25)<<endl;
            }
        }else{
            total+=((mini[i*2]+mini[i*2+2])/2);
            //cout<<((mini[i*2]+mini[i*2+2])/2)<<endl;
        }
        
    }
    cout<<setprecision(20)<<total<<endl;
    
    return 0;
}
