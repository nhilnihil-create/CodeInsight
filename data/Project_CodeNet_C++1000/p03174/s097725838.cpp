#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007

long long int arr[22][22];
long long int dp[1LL<<22];
long long int n; 

long long int comp(long long int index, long long int mask){
    if(index == n+1) return 1;
    if(dp[mask]!=-1) return dp[mask];
    long long int ans = 0;
    for(long long int i = 1; i <= n; i++){
        if(arr[index][i] && (mask&(1LL<<i))==0){
            ans = ((ans%mod) + (comp(index+1, mask|(1LL<<i)))%mod)%mod;
        }
    }
    return dp[mask] = ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> n;
    
    for(long long int i = 1; i <= n; i++){
        for(long long int j = 1; j <= n; j++){
            cin >> arr[i][j];
        }
    }
    memset(dp, -1, sizeof(dp));
    cout << comp(1, 0);
   return 0;
}