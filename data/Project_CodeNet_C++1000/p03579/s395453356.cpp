#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
typedef long long ll;
typedef pair<int,int> P;
typedef vector<int> vec;
typedef vector<vec> mat;
vec G[200001];
int V,color[200001];
bool dfs(int v,int c){
    color[v]=c;
    rep(i,G[v].size()){
        if(color[G[v][i]]==c) return false;
        if(color[G[v][i]]==0&&!dfs(G[v][i],-c)) return false;
    }
    return true;
}
int main(){
    ll n,m,a,b;
    cin>>n>>m;
    rep(i,m) cin>>a>>b,G[a].push_back(b),G[b].push_back(a);
    if(!dfs(1,1)) cout<<n*(n-1)/2-m;
    else{
        ll k=0,s=0;
        rep(i,n){
            if(color[i+1]==1) k++;
            else s++;
        }
        cout<<s*k-m;
    }
}