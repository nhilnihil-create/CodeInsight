#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,k;
    cin>>n>>k;
    vector<int> a(n);
    for(int i=0;i<n;i++)
    cin>>a[i];
    vector<int> dp(k+1,0);
    for(int i=0;i<=k;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(i-a[j]>=0&&!dp[i-a[j]])
            {
                dp[i]=1;
            }
        }
    }
    if(dp[k])
    cout<<"First"<<endl;
    else
    {
        cout<<"Second"<<endl;
    }
    
}