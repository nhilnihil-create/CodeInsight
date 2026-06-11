
#include <bits/stdc++.h>
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
ll inf=(ll)1E17;
#define rep(i,l,r) for(ll i=l;i<=r;i++)
#define pb push_back
ll max(ll a,ll b){if(a<b)return b;else return a;}
ll min(ll a,ll b){if(a>b)return b;else return a;}
void Max(ll &pos,ll val){pos=max(pos,val);}//Max(dp[n],dp[n-1]);
void Min(ll &pos,ll val){pos=min(pos,val);}
void Add(ll &pos,ll val){pos=mod(pos+val);}
long double EPS=1E-8;
///////////////////////////////////////

struct node{
    string a,b;
    bool operator<(const node x)const{
        if(a<x.a)return true;
        return a==x.a&&b<x.b;
    }
    bool operator==(const node x)const{
        return a==x.a&&b==x.b;
    }
};

int main(){
    ll n;cin>>n;
    string s;cin>>s;
    vector<node>v,w;;
    rep(i,0,(1<<n)-1){
        string a,b;
        rep(j,0,n-1){
            if((i>>j)&1)a+=s[j];
            else b+=s[j];
        }
        node x;x.a=a;x.b=b;
        v.pb(x);
    }
    reverse(s.begin(),s.end());
    rep(i,0,(1<<n)-1){
        string a,b;
        rep(j,0,n-1){
            if((i>>j)&1)a+=s[j];
            else b+=s[j];
        }
        node x;x.a=a;x.b=b;
        w.pb(x);
    }
    sort(v.begin(),v.end());sort(w.begin(),w.end());
    ll vpos=0,wpos=0;
    ll ans=0;
    while(vpos<=(1<<n)-1&&wpos<=(1<<n)-1){
        if(w[wpos]<v[vpos]){
            wpos++;
        }else if(v[vpos]<w[wpos]){
            vpos++;
        }else{
            ll xa=1,xb=1;
            while(vpos<=(1<<n)-2&&v[vpos]==v[vpos+1]){
                xa++;vpos++;
            }
            while(wpos<=(1<<n)-2&&w[wpos]==w[wpos+1]){
                xb++;wpos++;
            }
            vpos++;wpos++;
            ans+=xa*xb;
        }
    }
    cout<<ans<<endl;
    
    return 0;
}

