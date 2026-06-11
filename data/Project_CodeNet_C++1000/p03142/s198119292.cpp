#include<bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < n; i++)
#define pb push_back
using namespace std;
typedef long long ll;

int main(){
    int n,m;
    cin>>n>>m;
    vector<vector<int>> g(n);
    vector<set<int>> par(n);
    rep(i,n+m-1){
        int a,b;
        cin>>a>>b;
        a--; b--;
        g[a].pb(b);    
        par[b].insert(a);
    }

    int r;
    rep(i,n){
        if(par[i].empty()){
            r=i;
            break;
        }
    }

    queue<int> que;
    vector<int> ans(n);

    que.push(r);
    ans[r]=-1;

    while(!que.empty()){
        int x=que.front();
        que.pop();

        for(auto nx:g[x]){
            if(par[nx].size()==1){
                ans[nx]=x;
                que.push(nx);
            }
            if(par[nx].empty()) continue;        
            par[nx].erase(x);
        }
    }

    rep(i,n) cout<<ans[i]+1<<endl;
}