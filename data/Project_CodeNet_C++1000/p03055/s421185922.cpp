#include<bits/stdc++.h>
#include<unordered_set>
#include<unordered_map>
using namespace std;
#define REP(i,m,n) for(int i=(m);i<(n);i++)
#define rep(i,n) REP(i,0,n)
#include<bits/stdc++.h>
#include<unordered_set>
#include<unordered_map>
using namespace std;
#define REP(i,m,n) for(int i=(m);i<(n);i++)
#define rep(i,n) REP(i,0,n)
#define pb push_back
#define all(a) a.begin(),a.end()
#define rall(c) (c).rbegin(),(c).rend()
#define mp make_pair
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef long double ld;
const ll inf=1e9+7;
const ll mod=998244353;
vector<vector<ll> >G(2*100010);
ll ma=0;
ll s=1;
void dfs(ll i,ll p,ll d){
    if(d>ma){
        ma=d;
        s=i;
    }
    for(auto e:G[i]){
        if(e==p)continue;
        dfs(e,i,d+1);
    }
}
void dfs2(ll i,ll p,ll d){
    if(d>ma){
        ma=d;
    }
    for(auto e:G[i]){
        if(e==p)continue;
        dfs(e,i,d+1);
    }
}
int main(){
    ll n;cin>>n;
    rep(i,n-1){
        ll a,b;cin>>a>>b;
        G[a].pb(b);
        G[b].pb(a);
    }
    dfs(1,0,0);
    ma=0;
    dfs2(s,0,0);
    if(ma%3==1)cout<<"Second"<<endl;
    else cout<<"First"<<endl;
}