#include <bits/stdc++.h>

using namespace std;

int rec(int k, int n, int* arr, vector<int>& dp){
    if(dp[k]!=-1)
        return dp[k];
    if(k==0) return dp[k] = 0;
    int ans=0;
    for(int i=0;i<n;i++){
        if(arr[i]>k) continue;
        if(rec(k-arr[i],n,arr,dp)==0){
            ans = 1;
            break;
        }
    }
    
    return dp[k]=ans;
}

int main() {
    int n,k;
    cin>>n>>k;
    int arr[n];
    for(int i=0;i<n;i++)
        cin>>arr[i];
    vector<int> dp(k+1, -1);
    if(rec(k,n,arr,dp))
        cout<<"First\n";
    else
        cout<<"Second\n";
}