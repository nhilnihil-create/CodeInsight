#include<bits/stdc++.h>
using namespace std;

typedef int in;
#define int long long
#define push_back pb
int MAX=1e9;
int MAXEST=1e18;
int MOD=1e9+7;

int n;
int a[405];
int dp[405][405];

int cost(int s,int e){
    int x=0;
    if(s) x=a[s-1];
    return a[e]-x;
}
int f(int s, int e){
    if(s==e){
        return 0;
    }
    int &ret=dp[s][e];
    if(ret!=-1)
        return ret;
    ret=MAXEST;
    for(int i=s;i<e;i++){
        int x=cost(s,i)+f(s,i);
        int y=cost(i+1,e)+f(i+1,e);
        ret=min(ret,x+y);
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
        for(int i=0;i<n;i++){
            cin>>a[i];
            if(i)
                a[i]+=a[i-1];
        }
        memset(dp,-1,sizeof dp);
        cout<<f(0,n-1)<<endl;
    }
    return 0;
}
