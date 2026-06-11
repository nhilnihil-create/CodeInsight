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

struct U_F{
    vector<ll> par;
    vector<ll> rank;
private:
    vector<ll> num;
public:
    void init(ll n){
        rep(i,0,n-1){
            par.pb(i);
            rank.pb(0);
            num.pb(1);
        }
    }
    ll find(ll x){
        if(par[x]==x)return x;
        return par[x]=find(par[x]);
    }
    void unite(ll x,ll y){
        x=find(x);
        y=find(y);
        if(x==y)return;
        if(rank[x]<rank[y]){
            par[x]=y;
            num[y]=num[x]+num[y];
        }else if(rank[x]==rank[y]){
            par[y]=x;
            rank[x]++;
            num[x]=num[x]+num[y];
        }else{
            par[y]=x;
            num[x]=num[x]+num[y];
        }
    }
    bool same(ll x,ll y){
        return find(x)==find(y);
    }
    ll g_num(ll x){
        x=find(x);
        return num[x];
    }
};

int main(){fastio
    ll n,m;cin>>n>>m;
    ll p[n];
    rep(i,0,n-1){
        cin>>p[i];
        p[i]--;
    }
    ll x[m],y[m];
    U_F uf;
    uf.init(n);
    rep(i,0,m-1){
        cin>>x[i]>>y[i];
        x[i]--;
        y[i]--;
        
        uf.unite(x[i],y[i]);
    }
    map<ll,vector<ll>> mp;
    rep(i,0,n-1){
        ll par=uf.find(i);
        auto it=mp.find(par);
        if(it==mp.end()){
            vector<ll> v;
            v.pb(i);
            mp[par]=v;
        }else{
            mp[par].pb(i);
        }
    }
    
    
    
    vector<set<ll>> v[2];
    for(auto it=mp.begin();it!=mp.end();++it){
        vector<ll> u=(it->second);
        set<ll> st[2];
        rep(i,0,(ll)u.size()-1){
            st[0].insert(u[i]);
            st[1].insert(p[u[i]]);
        }
        v[0].pb(st[0]);
        v[1].pb(st[1]);
    }
    
    
    
    ll ans=0;
    rep(i,0,v[0].size()-1){
        for(auto it=v[0][i].begin();it!=v[0][i].end();++it){
            ll k=(*it);
            auto itr=v[1][i].find(k);
            if(itr!=v[1][i].end()){
                ans++;
            }
        }
    }
    cout<<ans<<endl;
    
    
        
    return 0;
}



