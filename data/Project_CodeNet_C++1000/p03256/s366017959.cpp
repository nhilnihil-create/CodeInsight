#include<bits/stdc++.h>
using namespace std;
#define int long long
#define REP(i,m,n) for(int i=(m);i<(n);i++)
#define rep(i,n) REP(i,0,n)
#define pb push_back
#define all(a) a.begin(),a.end()
#define rall(c) (c).rbegin(),(c).rend()
#define mp make_pair
#define endl '\n'
#define fi first
#define se second
typedef long long ll;
typedef pair<ll,ll> pll;
typedef long double ld;
const ll inf=1e9+7;
const ll mod=998244353;
signed main(){
    ll n,m;cin>>n>>m;
    string s;cin>>s;
    vector<vector<ll> >G(n);
    rep(i,m){
        ll a,b;cin>>a>>b;
        a--;b--;
        G[a].pb(b);
        G[b].pb(a);
    }
    rep(i,n){
        sort(all(G[i]));
        REP(j,1,G[i].size()){
            if(G[i][j]==G[i][j-1]){
                G[i].erase(G[i].begin()+j);
            }
        }
    }
    vector<ll>a(n),b(n);
    queue<ll>q;
    vector<ll>used(n);
    rep(i,n){
        for(auto e:G[i]){
            if(s[e]=='A')a[i]++;
            if(s[e]=='B')b[i]++;
        }
        if(a[i]>0&&b[i]>0)continue;
        q.push(i);
        used[i]=1;
    }
    while(!q.empty()){
        ll k=q.front();
        q.pop();
        for(auto e:G[k]){
            if(used[e])continue;
            if(e==k)continue;
            if(s[k]=='A')a[e]--;
            if(s[k]=='B')b[e]--;
            if(a[e]>0&&b[e]>0)continue;
            used[e]=1;
            q.push(e);
        }
    }
    bool f=0;
    rep(i,n){
        if(used[i]==0)f=1;
    }
    cout<<(f?"Yes":"No")<<endl;
}