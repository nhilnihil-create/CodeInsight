#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define black 1
#define white 0
typedef long long ll;

ll mod = 1000000007;
vector <vector<int>> adjlist(100001,vector<int>());
ll dp[100005][2];

ll go(int node,int parent,int paint)
{
    if(dp[node][paint] != -1)
        return dp[node][paint];
    
    ll w1  = 1;
    ll ans = 0;
    
    // white toh bacche ko paint kar hi sakte hain
    for(auto child : adjlist[node])
    {
        if(child != parent)
        {
            w1 = ((w1%mod)*(go(child,node,white)%mod))%mod;
        }
    }
    
    ans = (ans%mod + w1%mod)%mod;
    
    // agar parent white hai , tabhi bacche ko black karenge paint
    if(paint == white)
    {
        ll w2 = 1;
        for(auto child : adjlist[node])
        {
            if(child != parent)
            {
                w2 = ((w2%mod)*(go(child,node,black)%mod))%mod;
            }
        }
        ans = (ans%mod + w2%mod)%mod;
    }
    
    dp[node][paint] = ans;
    return ans;
}

int main()
{
    int n;
    cin >> n;
    
    memset(dp,-1,sizeof(dp));
    
    int a,b;
    for(int i=1;i<=n-1;i++)
    {
        cin >> a >> b;
        adjlist[a].push_back(b);
        adjlist[b].push_back(a);
    }
    
    cout << go(1,-1,white) << endl;
    
    return 0;
}