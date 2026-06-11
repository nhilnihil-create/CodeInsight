#include <bits/stdc++.h>
using namespace std;

int height(int h1,int h2)
{
    //cout<<"h1-"<<h1<<" h2-"<<h2<<" height-"<<abs(h1-h2)<<endl;
    return abs(h1-h2);
}

int frogjumps(int n,int *a)
{
    if(n==2)
        return height(a[0],a[1]);
    int dp[n];
    //cout<<"initial dp ";
    for(int i=0;i<n-1;i++)
    {
        dp[i]=INT_MAX;
        //cout<<dp[i]<<" ";
    }
    dp[n-1]=0;
    //cout<<dp[n-1]<<endl;
    for(int i=n-1;i>0;i--)
    {
        if(i-1>=0)
        {
            dp[i-1]=min(dp[i-1],(dp[i]+height(a[i],a[i-1])));
            //cout<<"if "<<a[i-1]<<" to "<<a[i]<<" = "<<dp[i-1]<<endl;
        }
        if((i-2)>=0)
        {
            dp[i-2]=min(dp[i-2],(dp[i]+height(a[i],a[i-2])));
            //cout<<"if "<<a[i-2]<<" to "<<a[i]<<" = "<<dp[i-2]<<endl;
        }
    }
    // for(int i=0;i<n;i++)
    //     cout<<dp[i]<<" ";
    // cout<<endl;
    return dp[0];
}

int main() {
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)
        cin>>a[i];
    // for(int i=0;i<n;i++)
    //     cout<<a[i]<<" ";
    // cout<<endl;
    cout<<frogjumps(n,a)<<endl;
    
}
