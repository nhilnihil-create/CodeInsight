#include<bits/stdc++.h>
using namespace std;
 
//keep coding
//-Roshan Mitra (SIT Pune) 
typedef vector <int> vi;
typedef pair< int ,int > pii;
#define endl "\n"
#define f0(i,n) for(int i=0;i<n;i++) 
#define f1(i,n) for(int i=1;i<=n;i++)
#define sd(val) scanf("%d",&val)
#define ss(val) scanf("%s",&val)
#define sl(val) scanf("%lld",&val)
#define debug(val) printf("check%d\n",val)
#define all(v) v.begin(),v.end()
#define pb push_back
#define MP make_pair
#define FF first
#define SS second
#define int long long
#define MOD 1000000007
#define clr(val) memset(val,0,sizeof(val))
#define what_is(x) cerr << #x << " is " << x << endl;
#define OJ \
    freopen("input.txt", "r", stdin); \
    freopen("output.txt", "w", stdout);
#define FIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
 
 int frogb(int ind,vector<int>&dp,int n,int k,int arr[]){
     if(ind==n-1)
        return 0;
    if(dp[ind]!=-1)
        return dp[ind];
    int miniCost = INT_MAX; 
    for(int i=ind+1;i<=min(n-1,ind+k);i++) {
        int cost = abs(arr[ind] - arr[i]) + frogb(i,dp,n,k,arr); 
        miniCost = min(cost, miniCost); 
        dp[ind]=miniCost;
    }
    return dp[ind];
 }
signed main()
{

 FIO;
 int n,k;
 cin>>n>>k;
 int arr[n];
 for(int i=0;i<n;i++)
    cin>>arr[i];
 vector<int>dp(n+1,-1);
 cout<<frogb(0,dp,n,k,arr)<<endl;
   
}