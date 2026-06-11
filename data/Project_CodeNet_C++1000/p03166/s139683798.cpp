#include<bits/stdc++.h>
#define int long long
using namespace std;

int  n , m  , Max=0;

vector<int > a[100010];

int  dp[100005];

void dfs(int  x , int  root , int  i)
{
    if(dp[x]!=0){return;}
    for(auto v: a[x])
    {
        if(v!=root&&v!=i)
        {
            dfs(v , x , i);
            dp[x]=max(dp[v]+1 , dp[x]);
        }
    }
}

main()
{
    cin >> n >> m ;
    for(int  i=1 ; i<=n ; i++){
        dp[i]=0;
    }
    for(int  i=1 ; i<=m ; i++){
        int  u , v;
        cin >> u >> v;
        a[u].push_back(v);
    }
    for(int  i=1 ; i<=n ; i++)
    {
        dfs(i , -1 , i);
        Max=max(dp[i] , Max);
    }
    cout << Max<<endl;
    
}

