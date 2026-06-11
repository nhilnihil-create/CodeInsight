#include <bits/stdc++.h>
using namespace std;

int func(vector<int>arr,int n,int k,int minv)
{
    vector<int>dp(k+1,1);

    for(int i=0;i<minv;i++)
    dp[i]=0;

    for(int i=minv;i<=k;i++)
    {
        for(int p=0;p<n;p++)
        {
           if(arr[p] <= i)
           {    
                int rem = i - arr[p];
                dp[i] = dp[i] & dp[rem];
                // if(dp[rem]==0) dp[i]=1;
           }
        }
        dp[i]=!dp[i];
    }

    return dp[k];
}

int main() {
    
    int n,k;  cin>>n>>k;
    vector<int>arr(n);
    for(int i=0;i<n;i++) cin>>arr[i];
    int minv = *min_element(arr.begin(),arr.end());
    int ans = func(arr,n,k,minv);
    if(ans==1) cout<<" First "<<endl;
    else cout<<" Second "<<endl;
}
