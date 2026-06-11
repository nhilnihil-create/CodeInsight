#include<bits/stdc++.h>
using namespace std;

typedef int in;
#define int long long
int MAX=1e9;
int MAXEST=1e18;
int MOD=1e9+7;

int n,k;
int a[105];
int dp[100005][2];

int f(int cur,bool t)
{
    int &ret=dp[cur][t];
    if(ret!=-1)
        return ret;
    if(t)
    {
        ret=0;
        for(int i=0; i<n; i++)
        {
            if(cur-a[i]>=0)
                ret=max(ret,f(cur-a[i],0));
            else
                break;
        }
    }
    else
    {
        ret=1;
        for(int i=0; i<n; i++){
            if(cur-a[i]>=0)
                ret=min(ret,f(cur-a[i],1));
            else
                break;
        }
    }
    return ret;
}

in main()
{
    int tc=1;
//    cin>>tc;
    while(tc--)
    {
        cin>>n>>k;
        for(int i=0; i<n; i++)
        {
            cin>>a[i];
        }
        sort(a,a+n);
        memset(dp,-1,sizeof dp);
        int ans=f(k,0);
        cout<<(ans==0?"First":"Second")<<endl;
    }
    return 0;
}
