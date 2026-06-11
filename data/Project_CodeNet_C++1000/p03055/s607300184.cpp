#include <bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define rep(i,n)   FOR(i,0,n)
#define pb emplace_back
typedef long long ll;
typedef pair<int,int> pint;

int n;
vector<int> vp[200001];
int d[200001];
int mx;
void dfs(int s,int par,int dt){
    d[s]=dt;
    if(d[mx]<d[s]) mx=s;
    rep(i,vp[s].size()){
        if(vp[s][i]!=par){
            dfs(vp[s][i],s,dt+1);
        }
    }
}
int main(){
    int ai,bi;
    cin>>n;
    rep(i,n-1){
        cin>>ai>>bi;
        --ai;--bi;
        vp[ai].pb(bi);
        vp[bi].pb(ai);
    }
    dfs(0,-1,0);
    memset(d,0,sizeof(d));
    dfs(mx,-1,0);
    cerr<<d[mx]<<endl;
    if(d[mx]%3==1){
        cout<<"Second"<<endl;
    }
    else{
        cout<<"First"<<endl;
    }
    return 0;
}
