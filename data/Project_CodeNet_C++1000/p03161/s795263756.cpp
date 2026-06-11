#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
    int n,k;
    cin>>n>>k;
    vector<int> a(n),dp(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    dp[0] = 0;
    for(int i=1;i<n;i++){
        int val = INT_MAX;
        for(int j=1;j<=k;j++){
            if(i-j < 0){
                break;
            }
            val = min(val,dp[i-j] + abs(a[i] - a[i-j]));
        }
        dp[i] = val;
    }
    cout<<dp[n-1];
    return 0;
}