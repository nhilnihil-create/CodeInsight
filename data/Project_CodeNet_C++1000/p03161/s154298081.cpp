#include <bits/stdc++.h>
#define ll long long
using namespace std;
 
void solve(){
    int n,k;
    cin>>n>>k;
    vector<int> arr(n),dp(n);
    for(int i=0;i<n;i++)
        cin>>arr[i];
    dp[0]=0;
    for(int i=1;i<n;i++){
        dp[i]=INT_MAX;
        for(int j=max(0,i-k);j<i;j++)
            dp[i]=min(dp[i],dp[j]+abs(arr[i]-arr[j]));
    }
    cout<<dp[n-1];
}

int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    solve(); cout<<endl;
    return 0;
}