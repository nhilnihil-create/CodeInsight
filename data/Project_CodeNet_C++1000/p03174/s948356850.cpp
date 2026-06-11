#include<bits/stdc++.h>
using namespace std;

typedef int in;
#define int long long
int MAX=1e9;
int MAXEST=1e18;
int MOD=1e9+7;

int n;
int a[30][30];
int dp[1<<22];

int f(int mask){
    if(mask==(1<<n)-1){
        return 1;
    }
    int &ret=dp[mask];
    if(ret!=-1)
        return ret;
    ret=0;
    int men=__builtin_popcountll(mask);
    for(int i=0;i<n;i++){
        if(a[men][i]==0||((1<<i)&mask))
            continue;
        ret+=f(mask|(1<<i));
        ret%=MOD;
    }
    return ret;
}

in main()
{
    int tc=1;
//    cin>>tc>>st;
    while(tc--)
    {
        cin>>n;
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<n; j++)
            {
                cin>>a[i][j];
            }
        }
        memset(dp,-1,sizeof dp);
        cout<<f(0)<<endl;
    }
    return 0;
}
