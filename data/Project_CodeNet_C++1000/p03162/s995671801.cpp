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
 int a[100001],b[100001],c[100001];
 int n;
int vacation(int ind , int flag, vector<vector<int>>&dp)
{
    if (ind == n )    return 0;
    if (dp[ind][flag] != -1)   return dp[ind][flag];
    if (flag == 0) //sob select korte parbe
        return dp[ind][flag] = max( a[ind] + vacation(ind + 1, 1, dp) , max( b[ind] + vacation(ind + 1, 2, dp) , c[ind] + vacation(ind + 1, 3, dp) ));
    else if (flag == 1) //b c choose only
        return dp[ind][flag] = max( b[ind] + vacation(ind + 1 , 2, dp) , c[ind] + vacation(ind + 1, 3, dp) );
    else if (flag == 2) //a c choose only
        return dp[ind][flag] = max( a[ind] + vacation(ind + 1 , 1, dp) , c[ind] + vacation(ind + 1, 3, dp) );
    else if (flag == 3) //b a choose only
        return dp[ind][flag] = max( b[ind] + vacation(ind + 1 , 2, dp) , a[ind] + vacation(ind + 1, 1, dp) );
}
signed main()
{

 FIO;
 cin>>n;
for(int i=0;i<n;i++){
        cin>>a[i]>>b[i]>>c[i];
}
 vector<vector<int>>dp(n+1,vector<int>(4,-1));
 cout<<vacation(0,0,dp);
}