#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9+7;

long long rangeSum(long long s, long long e, vector<long long>& pref){
    if(s==0) return pref[e];
    return pref[e]-pref[s-1];
}

long long rec(long long s, long long e, vector<long long>& pref, vector<vector<long long>>& dp){
    if(s==e) return 0ll;
    if(dp[s][e]!=-1)
        return dp[s][e];
    long long ans = LLONG_MAX;
    for(int i=s;i<e;i++){
        long long temp = rangeSum(s,i, pref)+rangeSum(i+1,e,pref)+rec(s,i,pref,dp)+rec(i+1,e,pref,dp);
        ans = min(ans, temp);
    }
    return dp[s][e] = ans;
}

int main() {
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
        cin>>arr[i];
    vector<long long> pref(n);
    vector<vector<long long>> dp(n+1, vector<long long>(n+1, -1));
    pref[0] = arr[0];
    for(int i=1;i<n;i++)
        pref[i] = pref[i-1]+arr[i];
    cout<<rec(0,n-1,pref,dp)<<"\n";
}