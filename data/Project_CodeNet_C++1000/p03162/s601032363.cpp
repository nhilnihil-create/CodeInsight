#include <bits/stdc++.h>
//#define DEBUG
using namespace std;
typedef long long ll;

vector<ll> num;
ll d, k, c,m,mod=1e9+7;
ll arr[100001][4],dp[100001][4];
ll mxlids,cnt,res;
ll a,b,n,pt,nt;
set<ll> s;
ll maxn=1e18+1;

ll func(int curr,int idx)
{
    if(idx==n) return 0;

    if(dp[idx][curr]!=-1) return dp[idx][curr];

    ll mx=0;

    if(curr==0)
    {
        mx=func(1,idx+1)+arr[idx][1];
        mx=max(mx,func(2,idx+1)+arr[idx][2]);
        mx=max(mx,func(3,idx+1)+arr[idx][3]);
    }
    else if(curr==1)
    {
        mx=max(mx,func(2,idx+1)+arr[idx][2]);
        mx=max(mx,func(3,idx+1)+arr[idx][3]);
    }
    else if(curr==2)
    {
        mx=max(mx,func(1,idx+1)+arr[idx][1]);
        mx=max(mx,func(3,idx+1)+arr[idx][3]);
    }
    else
    {
        mx=max(mx,func(1,idx+1)+arr[idx][1]);
        mx=max(mx,func(2,idx+1)+arr[idx][2]);
    }

    return dp[idx][curr] = mx;
}

int main()
{
    #ifdef DEBUG
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
        
    cin>>n;

    for (int i = 0; i < n; ++i)
    {
        for (int j=1;j<=3;j++)
        {
            cin>>arr[i][j];
        }
    }

    memset(dp,-1,sizeof(dp));
    cout<<func(0,0);
    
}