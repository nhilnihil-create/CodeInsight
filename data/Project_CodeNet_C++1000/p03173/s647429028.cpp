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
ll dp[401][401];
ll cost[401][401];
ll solve(int i,int j,vector<ll> &arr){
    if(i>=j)
    return 0;
    if(dp[i][j]!=-1)
    return dp[i][j];
    ll sum=LLONG_MAX;
    for(int k=i;k<j;k++){
        sum=min(solve(i,k,arr)+solve(k+1,j,arr)+cost[i][j],sum);
    }
    return dp[i][j]=sum;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int n;
    cin>>n;
    vector<ll> arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    memset(cost,0,sizeof cost);
    for(int i=0;i<n;i++){
        cost[i][i]=arr[i];
    }
    for(int i=0;i<n;i++){
        for(int j=1;j<n;j++){
            if(i>j)continue;
            else{
                cost[i][j]=cost[i][j-1]+arr[j];
            }
        }
    }
    memset(dp,-1,sizeof dp);
    ll ans=solve(0,n-1,arr);
    cout<<ans;
    return 0;
}