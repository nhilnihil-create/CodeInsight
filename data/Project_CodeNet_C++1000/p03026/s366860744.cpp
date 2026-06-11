#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
ll c[10005],deg[10005],val[10005],res;
void dfs(ll i,ll p,vector<vector<ll>> &v){
    for(ll j=0;j<v[i].size();j++)
    if(v[i][j]!=p){
        res+=min(val[i],val[v[i][j]]);
        dfs(v[i][j],i,v);
    }
}
void bfs(ll n,vector<vector<ll>> &v){
    set<ll> s;
    vector<ll> vis(n+1,0);
    ll k=1;
    for(ll i=1;i<=n;i++)
    if(deg[i]==1){
        s.insert(i);
        deg[i]--;
    }
    while(!s.empty()){
        set<ll> temp,jok;
        for(auto it=s.begin();it!=s.end();it++)
        vis[*it]=1;
        for(auto it=s.begin();it!=s.end();it++){
            ll i=(*it);
            for(ll j=0;j<v[i].size();j++)
            if(!vis[v[i][j]]){
                deg[v[i][j]]--;
                if(deg[v[i][j]]==1)
                temp.insert(v[i][j]);
                else if(deg[v[i][j]]==0){
                    temp.erase(v[i][j]);
                    jok.insert(v[i][j]);
                }
            }
            val[i]=c[k++];
        }
        for(auto it=jok.begin();it!=jok.end();it++)
        val[*it]=c[k++];
        s=temp;
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll n;
    cin>>n;
    vector<vector<ll>> v(n+1);
    for(ll i=0;i<n-1;i++){
        ll a,b;
        cin>>a>>b;
        v[a].push_back(b);
        v[b].push_back(a);
        deg[a]++;
        deg[b]++;
    }
    for(ll i=1;i<=n;i++)
    cin>>c[i];
    sort(c,c+n+1);
    bfs(n,v);
    dfs(1,0,v);
    cout<<res<<endl;
    for(ll i=1;i<=n;i++)
    cout<<val[i]<<" ";
}
