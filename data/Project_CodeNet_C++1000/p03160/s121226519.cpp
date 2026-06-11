#include <bits/stdc++.h>
typedef long long int lli;
#define mod 1000000007
#define MOD 1003
#define li long int
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin>>n;
    int arr[n+1];
    for (int i=0;i<n;i++) cin>>arr[i];
    int dp[n+1];
    for (int i=0;i<n+1;i++) dp[i]=INT_MAX;
    dp[0]=0;
    dp[1]=abs(arr[0]-arr[1]);
    for (int i=2;i<n;i++){
        dp[i]=min(dp[i-2]+abs(arr[i]-arr[i-2]),dp[i-1]+abs(arr[i-1]-arr[i]));
    }
    cout<<dp[n-1]<<'\n';

}
