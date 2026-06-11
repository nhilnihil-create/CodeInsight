#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int compute(int k, int n, vector<int>&dp, int arr[])
{
    if(k==0)
    return 0;
    
    int ans=0;
    // cout<<k<<" ";
    
    if(dp[k]!=-1)
        return dp[k];
        
    for(int i=0;i<n;i++)
    {
        if(arr[i]<=k)
        {
            if(compute(k-arr[i],n,dp,arr)==0)
            {ans=1;
            break;}
        }
    }
    // cout<<ans<<endl;
    return dp[k]=ans;
    
}

int main() {
// 	cout<<"GfG!";

    int N,K;
    cin>>N>>K;
    int arr[N];
    
    for(int i=0;i<N;i++)
        cin>>arr[i];
    sort(arr,arr+N);
    vector<int>dp(K+1,0);
    dp[0]=0;
    for(int i=0;i<=K;i++)
    {
        for(int j=0;j<N;j++)
        {
            if(arr[j]>i)
                break;
            if(dp[i-arr[j]]==0)
            {
                dp[i]=1;
                break;
            }
        }
    }
    if(dp[K]==1)
        cout<<"First";
    else
        cout<<"Second";
    
	return 0;
}