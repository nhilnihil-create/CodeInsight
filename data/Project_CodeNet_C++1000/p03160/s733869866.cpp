#include<bits/stdc++.h>
using namespace std;
int mini(int h[],int n) {
    int dp[n+1],i,j;
     dp[1] = 0;
     dp[2] = abs(h[1]-h[0]);
    for(i=3;i<=n;i++) {
        dp[i] =  min(dp[i-1] + abs(h[i-2]-h[i-1]),dp[i-2]+abs(h[i-3]-h[i-1]));
    }
    return dp[n];
}
int main() {
     int n;
    cin>>n;
    int a[n],i;
    for(i=0;i<n;i++) {
        cin>>a[i];
    }
    cout<<mini(a,n)<<"\n";
}