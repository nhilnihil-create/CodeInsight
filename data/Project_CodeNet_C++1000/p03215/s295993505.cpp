#include <bits/stdc++.h>
//#include <boost/multiprecision/cpp_int.hpp> namespace mp = boost::multiprecision; //mp::cpp_intで宣言
using namespace std;
typedef long long ll;
#define i_7 (ll)(1E9+7)
#define i_5 (ll)(1E9+5)
ll mod(ll a){
    ll c=a%i_7;
    if(c>=0)return c;
    else return c+i_7;
}
typedef pair<int,int> i_i;
typedef pair<ll,ll> l_l;
ll inf=(ll)1E12;//10^12
#define rep(i,l,r) for(ll i=l;i<=r;i++)
#define pb push_back
ll max(ll a,ll b){if(a<b)return b;else return a;}
ll min(ll a,ll b){if(a>b)return b;else return a;}
void Max(ll * pos,ll val){*pos=max(*pos,val);}//Max(&dp[i][j],dp[i-1][j]);
void Min(ll * pos,ll val){*pos=min(*pos,val);}
void Add(ll * pos,ll val){*pos=mod(*pos+val);}
const long double EPS=1E-8;
////////////////////////////////////////

//#define int ll

int main(){

    ll n,k;cin>>n>>k;
    ll a[n+1];rep(i,1,n)cin>>a[i];
    a[0]=0;rep(i,1,n)a[i]=a[i-1]+a[i];
    vector<ll>v;
    rep(i,1,n){
        rep(j,0,i-1){
            v.pb(a[i]-a[j]);
        }
    }
    //sort(v.begin(),v.end());
    /*for(auto x:v){
        cout<<x<<" ";
    }*/
    ll ans=0;
    int N=40;
    for(int i=N;i>=0;i--){
        ll p=(ll)1<<i;
        vector<ll>ok;
        for(auto x:v){
            if((x&p)==p){
                ok.pb(x);
            }
        }
        if(ok.size()>=k){
            ans+=p;
            v.clear();
            v=ok;
        }
       // cout<<i<<" "<<v.size()<<" "<<ok.size()<<endl;
        ok.clear();
    }

    cout<<ans<<endl;

    return 0;
}
