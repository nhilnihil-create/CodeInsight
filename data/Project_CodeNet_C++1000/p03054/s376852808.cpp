#include<bits/stdc++.h>
//ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
//clock_t start=clock();clock_t end=clock();cout<<(double)(end-start)/CLOCKS_PER_SEC<<endl;
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int ui;
typedef pair<int,int> pii;
typedef pair<pii,int> ppii;
typedef pair<int,pii> pipi;
typedef pair<ll,ll> pll;
typedef pair<pll,ll> ppll;
typedef pair<ll,pll> plpl;
typedef pair<pii,pii> P;
typedef tuple<ll,ll,ll> tl;
typedef pair<double,double> pdd;
typedef vector<vector<ll>> mat;
ll mod=1000000007;
ll mod2=998244353;
ll mod3=1000003;
ll mod4=998244853;
ll mod5=1000000009;
ll inf=1LL<<62;
double pi=3.141592653589793238462643383279L;
double eps=1e-14;
#define rep(i,m,n) for(ll i=m;i<n;i++)
#define rrep(i,n,m) for(ll i=n;i>=m;i--)
#define srep(itr,st) for(auto itr=st.begin();itr!=st.end();itr++)
#define mrep(itr,mp) for(auto itr=mp.begin();itr!=mp.end();itr++)
#define Max(a,b) a=max(a,b)
#define Min(a,b) a=min(a,b)
int dh[4]={1,-1,0,0};
int dw[4]={0,0,1,-1};
int ddh[8]={-1,-1,-1,0,0,1,1,1};
int ddw[8]={-1,0,1,-1,1,-1,0,1};
struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        // http://xorshift.di.unimi.it/splitmix64.c
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};
#define umh unordered_map<ll,ll,custom_hash>
ll gcd(ll a,ll b){
    if(a<b)swap(a,b);
    if(b==0)return a;
    if(a%b==0)return b;
    return gcd(b,a%b);
}
ll lcm(ll a,ll b){
    ll c=gcd(a,b);
    return a*b/c;
}
ll Pow(ll n,ll k){
    ll ret=1;
    ll now=n;
    while(k>0){
        if(k&1)ret*=now;
        now*=now;
        k/=2;
    }
    return ret;
}
ll beki(ll n,ll k,ll md){
  ll ret=1;
  ll now=n;
    now%=md;
  while(k>0){
    if(k%2==1){
      ret*=now;
      ret%=md;
    }
    now*=now;
    now%=md;
    k/=2;
  }
  return ret;
}
ll gyaku(ll n,ll md){
  return beki(n,md-2,md);
}
ll popcount(ll n){
    ll ret=0;
    ll u=n;
    while(u>0){
        ret+=u%2;
        u/=2;
        
    }
    return ret;
}

int main(){
    ios::sync_with_stdio(false);cin.tie(0);
    int h,w;cin>>h>>w;
    int n;cin>>n;
    int sh,sw;cin>>sh>>sw;
    string s,t;cin>>s>>t;
    vector<int> v;
    int now;
    v.clear();
    rep(i,0,n){
        if(s[i]=='L')v.push_back(-1);
        if(t[i]=='R')v.push_back(1);
    }
    now=sw;
    rep(i,0,v.size()){
        now+=v[i];
        Min(now,w);
        if(now==0){
            cout<<"NO"<<endl;
           // cout<<1;
            return 0;
        }
    }
    v.clear();
    rep(i,0,n){
        if(s[i]=='R')v.push_back(1);
        if(t[i]=='L')v.push_back(-1);
    }
    now=sw;
    rep(i,0,v.size()){
        now+=v[i];
        //cout<<now<<endl;
        Max(now,1);
        if(now==w+1){
            cout<<"NO"<<endl;
            //cout<<2;
            return 0;
        }
    }
    v.clear();
    rep(i,0,n){
        if(s[i]=='U')v.push_back(-1);
        if(t[i]=='D')v.push_back(1);
    }
    now=sh;
    rep(i,0,v.size()){
        now+=v[i];
        Min(now,h);
        if(now==0){
            cout<<"NO"<<endl;
            return 0;
        }
    }
    v.clear();
    rep(i,0,n){
        if(s[i]=='D')v.push_back(1);
        if(t[i]=='U')v.push_back(-1);
    }
    now=sh;
    rep(i,0,v.size()){
        now+=v[i];
        Max(now,1);
        if(now==h+1){
            cout<<"NO"<<endl;
            return 0;
        }
    }
    cout<<"YES"<<endl;
}

