#include<iostream>
#include<vector>

using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> arr(n), dp(n+1) ;
    for(int i = 0; i < n; i++) cin >> arr[i];
    
    int ans = 0;
    for(int i = 0; i < n; i++)
{
    dp[arr[i]] = dp[arr[i] -1] + 1;
ans = max(ans, dp[arr[i]]);	//cout << dp[arr[i]] << " "; 
}
cout << n - ans ;

} 
