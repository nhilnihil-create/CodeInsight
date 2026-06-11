#include<bits/stdc++.h>
using namespace std;

#define MOD 1000000007;

int dp[1001][1001];


int solve(vector<vector<char>>&v,int x1,int y1,int x2,int y2)
{
    if(dp[x1][y1]!=-1)
        return dp[x1][y1];
    if(x1==x2&&y1+1==y2)
        return dp[x1][y1]=1;
    if(y1==y2&&x1+1==x2)
        return dp[x1][y1]=1;

    int op1=0,op2=0;
    if(y1+1<=y2&&v[x1][y1+1]!='#')
    {
        op1=solve(v,x1,y1+1,x2,y2)%MOD;
        dp[x1][y1+1]=op1%MOD;
    }
    if(x1+1<=x2&&v[x1+1][y1]!='#')
    {
        op2=solve(v,x1+1,y1,x2,y2)%MOD;
        dp[x1+1][y1]=op2%MOD;
    }
    
    return dp[x1][y1]=(op1+op2)%MOD;
}

int main()
{
    int r,c;
    cin>>r>>c;
    vector<vector<char>> v;
    memset(dp,-1,sizeof dp);
    for(int i=0; i<r; i++)
    {
        vector<char> vi(c);
        for(int j=0; j<c; j++)
            cin>>vi[j];
        v.push_back(vi);
    }
    cout<<solve(v,0,0,r-1,c-1);
    return 0;
}