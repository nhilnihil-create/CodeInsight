#include<bits/stdc++.h>
using namespace std;

typedef int in;
#define int long long
int MAX=1e9;
int MAXEST=1e18;
int MOD=1e9+7;

int n,m;
vector<int> v[100005];
int dp[100005];

int f(int idx){
    int &ret=dp[idx];
    if(ret!=-1)
        return ret;
    ret=0;
    for(int i=0;i<v[idx].size();i++){
        ret=max(ret,f(v[idx][i])+1);
    }
    return ret;
}

in main()
{
    int tc=1;
//    cin>>tc;
    while(tc--)
    {
        cin>>n>>m;
        for(int i=0;i<m;i++){
            int x,y;
            cin>>x>>y;
            v[x].push_back(y);
        }
        memset(dp,-1,sizeof dp);
        int ans=1;
        for(int i=1;i<=n;i++){
            ans=max(ans,f(i));
        }
        cout<<ans<<endl;
    }
    return 0;
}
