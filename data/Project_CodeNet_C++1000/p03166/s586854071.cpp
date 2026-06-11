#include<bits/stdc++.h>
#define pi pair<int,int>
#define mk make_pair
#define f(i,n) for(int i=0;i<n;i++)
#define fo(i,a,n) for(int i=a;i<n;i++)
#define fr(i,a,n) for(int i=a;i>=n;i--)
#define ll long long
#define N 1000000
using namespace std;

vector<int> adj[100005];
vector<int> dp(100005,-1);

void addedge(int x,int y)
{
    adj[x].push_back(y);
}

int dfs(int ind)
{
    if(dp[ind]==-1)
    {
        int ans=0;
        for(auto i:adj[ind])
        {
           ans=max(ans,dfs(i)+1);
        }
       dp[ind]=ans;
    }
    return dp[ind];
}


int longestpath(int n)
{
    int answer=INT_MIN;
    fo(i,1,n+1)
    {
        answer=max(answer,dfs(i));
    }
    return answer;
}



int main()
{
    int n,m;
    cin>>n>>m;
    int x,y;
    f(i,m)
    {
        cin>>x>>y;
        addedge(x,y);
    }
    cout<<longestpath(n);
}
