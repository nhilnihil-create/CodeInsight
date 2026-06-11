#include <iostream>
#include <vector>
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
    
    vector<int>dp(K+1,-1);
    
    if(compute(K,N,dp,arr)==1)
        cout<<"First";
    else
        cout<<"Second";
    
	return 0;
}