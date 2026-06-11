#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define SPEED ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define MOD 1000000007
signed main()
{
    SPEED;
    int n,k;
    cin>>n>>k;
    int a[n],dp[k+1]={0},flag=0;
    vector <int> chk;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
        if(a[i]<=k)
        chk.push_back(a[i]);
    }
    n=chk.size();
    if(n==0)
    {
        cout<<"Second";
        return 0;
    }
    for(int i=1;i<=k;i++)
    {
        int f=0;
        for(int j=0;j<n;j++)
        {
            if(i-chk[j]>=0 && dp[i-chk[j]]==0)
            f=1;
        }
        dp[i]=f;
    }
    if(dp[k])
    cout<<"First";
    else
    cout<<"Second";
}