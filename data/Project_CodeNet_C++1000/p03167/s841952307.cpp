#include<bits/stdc++.h>
using namespace std;

typedef int in;
#define int long long
int MAX=1e8;
int MAXEST=1e18;
int MOD=1e9+7;

int h,w;
int dp[1005][1005];
string grid[1005];

int f(int idx1,int idx2)
{
    if(idx1==h-1&&idx2==w-1)
        return 1;
    int &ret=dp[idx1][idx2];
    if(ret!=-1)
        return ret;
    ret=0;
    if(grid[idx1+1][idx2]=='.'&&idx1+1<=h-1)
        ret=f(idx1+1,idx2);
    if(grid[idx1][idx2+1]=='.'&&idx2+1<=w-1)
        ret+=f(idx1,idx2+1);
    return ret%MOD;
}

in main()
{
    int tc=1;
//    cin>>tc;
    while(tc--)
    {
        cin>>h>>w;
        for(int i=0;i<h;i++){
            cin>>grid[i];
        }
        memset(dp,-1,sizeof dp);
        cout<<f(0,0)<<endl;
    }
    return 0;
}
