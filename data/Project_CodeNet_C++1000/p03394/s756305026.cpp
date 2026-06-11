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
ll inf=(ll)1E17;
#define rep(i,l,r) for(ll i=l;i<=r;i++)
#define pb push_back
ll max(ll a,ll b){if(a<b)return b;else return a;}
ll min(ll a,ll b){if(a>b)return b;else return a;}
void Max(ll &pos,ll val){pos=max(pos,val);}//Max(dp[n],dp[n-1]);
void Min(ll &pos,ll val){pos=min(pos,val);}
void Add(ll &pos,ll val){pos=mod(pos+val);}
dd EPS=1E-9;
#define fastio ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
///////////////////////////////////////

int main(){fastio
    
    ll a[8]={2,3,4,6,8,9,10,12};
    ll n;cin>>n;
    
    if(n==3){
        cout<<"2 5 63"<<endl;return 0;
    }
    if(n==4){
        cout<<"2 5 20 63"<<endl;return 0;
    }
    
    rep(i,1,n/8){
        rep(j,0,7){
            cout<<(i-1)*12+a[j]<<" ";
        }
    }
    ll add=(n/8)*12;
    rep(i,0,(1<<8)-1){
        ll sum=0;
        ll c=0;
        rep(j,0,7){
            if((i>>j)&1){
                sum+=a[j];
                c++;
            }
        }
        if(abs(c-n)%8==0){
            if(sum%6==0){
                rep(j,0,7){
                    if((i>>j)&1){
                        cout<<add+a[j]<<" ";
                    }
                }
                return 0;
            }
        }
    }
    
    
    return 0;
}

