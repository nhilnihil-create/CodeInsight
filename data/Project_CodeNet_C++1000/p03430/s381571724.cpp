#include <bits/stdc++.h>

using namespace std;

#define N 305
#define int long long

int dp[N][N][N];
string s;

int find(int l, int r, int x)
{
    if(l>r || x<0)
        return 0;

    if(dp[l][r][x]!=-1)
        return dp[l][r][x];

    if(l==r)
    {
        return dp[l][r][x]=1;
    }

    int x1 = find(l+1,r,x);
    x1 = max(x1, find(l,r-1,x));
    
    if(s[l]==s[r])
    {
        x1 = max(x1, 2+find(l+1,r-1,x));
    }
    else if(x>0){
        x1 = max(x1, 2+find(l+1,r-1,x-1));
    }

    //cout<<l<<" "<<r<<" "<<x<<" "<<x1<<endl;
    return dp[l][r][x]=x1;

}

int32_t main()
{
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++)
        {
            for(int k=0;k<N;k++)
            {
                dp[i][j][k] = -1;
            }
        }
    }

    cin>>s;
    int x;
    cin>>x;
    int n = s.length();
    cout<<find(0,n-1,x)<<endl;

    return 0;
}
