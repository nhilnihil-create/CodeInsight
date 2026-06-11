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

ll n,m;
bool seen[100001];
ll x[100001];
struct vv{ ll to,d;};
vector<vv> v[100001];

bool hoge(ll a){
    seen[a]=true;
    if(v[a].size()==0){
        return true;
    }
    rep(i,0,v[a].size()-1){
        if(seen[v[a][i].to]){
            if(x[v[a][i].to]!=x[a]+v[a][i].d){
                //cout<<a<<' '<<v[a][i].to<<' '<<x[a]<<' '<<v[a][i].d<<' '<<x[v[a][i].to]<<endl;
                return false;
            }
        }else{
            x[v[a][i].to]=x[a]+v[a][i].d;
            if(!hoge(v[a][i].to))return false;
        }
    }
    return true;
}


int main(){
    cin>>n>>m;
    ll l,r,d;
    vv ve;
    rep(i,0,m-1){
        cin>>l>>r>>d;
        ve.to=r;
        ve.d=d;
        v[l].pb(ve);
        ve.to=l;
        ve.d=-d;
        v[r].pb(ve);
    }
    rep(i,0,n){
        x[i]=inf;
    }
    rep(i,1,n){
        if(seen[i]){
            continue;
        }
        x[i]=0;
        if(!hoge(i)){
            cout<<"No"<<endl;
            //cout<<i<<endl;
            return 0;
        }
    }
    cout<<"Yes"<<endl;
    return 0;
}
