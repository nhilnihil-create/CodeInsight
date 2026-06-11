#include<bits/stdc++.h>
using namespace std;
#define int long long
int n;
int vis[100005]={0};
vector<int> grph[100005];
int mo=1000000007;
pair<int,int> dfs(int a,int p)
{
    if(vis[a]==0)
    {
        vis[a]=1;
        pair<int,int> ans;
        ans.first=1;
        ans.second=1;
        for(auto &k:grph[a])
        {
            if(k!=p)
            {
                pair<int,int> temp=dfs(k,a);
                ans.first=(ans.first * (temp.first + temp.second)%mo)%mo;
                ans.second=(ans.second * temp.first)%mo;
            }
        }
        //cout<<a<<" "<<ans.first<<" "<<ans.second<<"\n";
        return ans;
    }
}


int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n;
    for(int i=0;i<(n-1);i++)
    {
        int x,y;
        cin>>x>>y;
        grph[x].push_back(y);
        grph[y].push_back(x);
    }
    pair<int,int> ans=dfs(1,0);
    cout<<(ans.first + ans.second)%mo;
}
