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
 
 int frogA(int ind,vector<int>&dp,int n,int arr[]){
     if(ind==n-1)
        return 0;
    if(dp[ind]!=-1)
        return dp[ind];
    int c1=INT_MAX;
    c1=abs(arr[ind]-arr[ind+1])+frogA(ind+1,dp,n,arr);
    int c2=INT_MAX;
    if(ind+2<=n-1){
        c2=abs(arr[ind]-arr[ind+2])+frogA(ind+2,dp,n,arr);
    }
    dp[ind]=min(c1,c2);
    return dp[ind];
 }
signed main()
{

 FIO;
 int n;
 cin>>n;
 int arr[n];
 for(int i=0;i<n;i++)
    cin>>arr[i];
 vector<int>dp(n+1,-1);
 cout<<frogA(0,dp,n,arr)<<endl;
   
}