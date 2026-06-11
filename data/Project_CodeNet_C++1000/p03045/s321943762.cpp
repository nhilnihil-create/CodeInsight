#include <bits/stdc++.h>
    #include <math.h>

    using namespace std;
    typedef long long ll;
    typedef unsigned long long ull;
    # define M_PI  3.14159265358979323846


    vector<int>adj[100005];
    bool vist[100005];

    void dfs(int u){
        if(!vist[u]){
            vist[u]=1;
            for(auto v : adj[u])
                dfs(v);
        }
        return;
    }

    void solve(){
        int n,m;
        cin>>n>>m;
        for(int i=0;i<m;i++){
            int x,y,z;
            cin>>x>>y>>z;
            adj[x].push_back(y);
            adj[y].push_back(x);
        }
        memset(vist,false,sizeof(vist));
        int ans=0;
        for(int i=1;i<=n;i++){
            if(!vist[i]){
                ans++;
                dfs(i);
            }
        }
        cout<<ans;
    }
    int main(){
        ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        cout<<fixed;
        cout<<setprecision(10);
        int t=1;
//        cin>>t;
        for(int i=1;i<=t;i++){
            solve();
        }
        return 0;
    }
