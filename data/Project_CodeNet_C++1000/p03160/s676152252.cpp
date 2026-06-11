#include<bits/stdc++.h>
using namespace std;
long long int dp[200005];
long long int n;
vector<long long int > arr(200005);
void gen(long long int x)
{
    for(int i=x;i<n;i++)
        dp[i]=min(dp[i-1]+abs(arr[i]-arr[i-1]),dp[i-2]+abs(arr[i]-arr[i-2]));
}
int main()
{
   // int n;
    cin>>n;
   // vector<int> arr(n);
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    //input part has been done

   // long long int mini=1e5;
    //initialization
    dp[0]=0;
    dp[1]=abs(arr[0]-arr[1]);

    gen(2);
    cout<<dp[n-1];
}
