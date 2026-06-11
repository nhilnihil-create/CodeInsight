////=====BIsmiintahir Rahmanir Rahim =====////

/*                        ______
 _______   /\     |``\   |        |  /
    |     /  \    |__/   |____    |/
    |    / _ _\   |  \   |        |\
    |   /      \  |   \  |______  |  \

            Dept. of CSE
         Comiinta University

*/
#include<bits/stdc++.h>
using namespace std;

const int maX=1e5+5;
vector<int>ara[maX];
int dp[maX];
int v[maX];
int dfs(int x){
    if(v[x]==1)return dp[x];
    int ans=0;
    for(int i=0;i<ara[x].size();i++){
        ans=max(ans,1+dfs(ara[x][i]));
    }
    v[x]=1;
    dp[x]=ans;
    return ans;
}

int main()
{
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=m;i++){
        int x,y;
        cin>>x>>y;
        ara[x].push_back(y);
    }
    int mx=-1;
    for(int i=1;i<=n;i++){
        dfs(i);
        mx=max(dp[i],mx);
    }
    cout<<mx<<endl;
return 0;
}
