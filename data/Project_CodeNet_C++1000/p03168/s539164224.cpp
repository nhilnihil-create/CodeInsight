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
 
#define N  int(3010)+10
double  dp[N][N];double p[N];
int main()
{    SPEED;
       int n,x;
       cin>>n;
       loop(i,1,n+1){
       	 cin>>p[i] ;
       }
        dp[0][0] = 1 ;
       loop(i,1,n+1){
       	  
       	   loop(heads,0,i+1){
       	   	 if(heads==0){
       	   	 	 dp[i][heads] = (1-p[i])*dp[i-1][heads] ;continue ;
       	   	 }
       	   	 dp[i][heads] = p[i]*dp[i-1][heads-1]+(1-p[i])*dp[i-1][heads] ;
       	   }
       } double sm =0 ;
       loop(heads,0,n+1){
       	  if(heads>n/2)sm+=dp[n][heads] ;
       } 
       cout<<fixed<<stp<<sm;
}