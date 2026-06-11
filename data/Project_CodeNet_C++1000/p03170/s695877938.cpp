#include<bits/stdc++.h>
using namespace std;
int dp[200005];
int main()
{
    int n,k;
    cin>>n>>k;
    int a[n];
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    for(int i=0;i<=k;i++)
    {
        if(dp[i]!=true)
        {
        for(int j=0;j<n;j++)
        {
            dp[i+a[j]]=true;
           // if(dp[])
        }
    }
    }
    if(dp[k]==true)
    {
        cout<<"First"<<endl;
    }
    else{
        cout<<"Second"<<endl;

    }
    return 0;
}
