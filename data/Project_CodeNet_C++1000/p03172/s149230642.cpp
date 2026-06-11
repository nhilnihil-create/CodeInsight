#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp> 
#include <functional> 
#define ff first 
#define endl "\n"
#define ss second 
#define li list<int>
#define vi vector<int>
#define ll long long int
#define pii pair<int,int>
#define vii vector<pair<int,int> >
#define mp make_pair
#define pb push_back
#define setbits(x) __builtin_popcountll(x)
#define custom  pair<int,pair<int,int> >
using namespace std;
using namespace __gnu_pbds;
typedef tree<int, null_type, less<int>, rb_tree_tag,tree_order_statistics_node_update> pbds; 
#define mod 1000000007
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int n,k;cin>>n>>k;
    ll arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    ll dp[n][k+1];
    for(int j=0;j<=k;j++){
        dp[0][j]=(j>arr[0])?0:1;
    }
    for(int i=1;i<n;i++){
        for(int j=0;j<=k;j++){
            if(j==0)
            dp[i][j]=dp[i-1][j];
            else{
                dp[i][j]=(dp[i-1][j]+dp[i][j-1]-((j>arr[i])? dp[i-1][j-arr[i]-1]:0)+mod)%mod;
            }
        }
    }
    cout<<dp[n-1][k];
    return 0;
}