//  Friendly NUKE is ready!!
#include <bits/stdc++.h>
#define SPEED ios::sync_with_stdio(false); cin.tie(0)
#define loop(i,a,b) for(int i=a;i<b;i++)
#define ll long long
#define vi vector<int>
#define vl vector<ll>
#define pii pair<int,int>
#define pll pair<long long int,long long int>
#define dbg(x) cout<<#x<<": "<<x<<endl
#define ff first
#define ss second
#define mp make_pair
#define pb push_back
#define mo 1000000007
#define inf 1e18
#define eps 0.0000000001
#define stp setprecision(20)
#define all(v) v.begin(),v.end()
#define endl '\n'
using namespace std;
//mt19937 rng32(chrono::steady_clock::now().time_since_epoch().count());
 
#define N  int(1010)+10
ll dp[N][N];char s[N][N] ;
int main()
{    SPEED;
       int n,x;
       cin>>n>>x;
       loop(i,1,n+1){
       	 loop(j,1,x+1)
       	  cin>>s[i][j];
       }
       if(s[1][1]!='#')
       dp[1][1]=1;
      
       loop(i,1,n+1){
       	  
       	   loop(j,1,x+1){
       	   	 if(s[i][j+1]!='#')
       	   	  dp[i][j+1]+=dp[i][j], dp[i][j+1]%=mo;
       	   	  if(s[i+1][j]!='#')
       	   	  dp[i+1][j]+=dp[i][j],dp[i+1][j]%=mo;
       	   }
       }
       cout<<dp[n][x]; 
}