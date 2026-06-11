#include <bits/stdc++.h>
/**
AHMAD;HASSAN;SAEED
*/
using namespace std;
int n;
long long rm=1e9+7;
int cnt=0;
vector<vector<int> >adj2;
vector<vector<long long> >dp;
long long slv(int v=0,int pr=0,int prnt=-1){
    cnt++;
    int cntt=0;
    long long ret=1ll;
    if(dp[v][pr]!=-1ll)
        return dp[v][pr];
    for(int i=0;i<adj2[v].size();i++){
        if(adj2[v][i]!=prnt){
            ///cout<<v<<' '<<adj2[v][i]<<'\n';
            cntt++;
            long long ttl=0ll;
            ttl+=slv(adj2[v][i],0,v);
            ttl%=rm;
            if(pr==0)
                ttl+=slv(adj2[v][i],1,v);
            ttl%=rm;
            ret*=ttl;
            ret%=rm;

        }
    }


    return dp[v][pr]=ret;
}
int main()
{

    cin>>n;
    vector<vector<int> >adj(n);
    for(int i=0;i<n-1;i++){
        int x,y;
        cin>>x>>y;
        x--;  y--;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    adj2=adj;
    dp=vector<vector<long long> >(n,vector<long long>(2,-1ll));
    cout<<(slv(0,0,-1)+slv(0,1,-1))%rm<<'\n';
    ///cout<<cnt<<'\n';
/**
10
8 5
10 8
6 5
1 5
4 8
2 10
3 6
9 2
1 7
*/
    return 0;
}
