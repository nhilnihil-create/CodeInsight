/* 
  		!!~~~~~~~~~~~~~~~~~~     
  	#include < ~_~ Ajay > 
 	 	~~~~~~~~~~~~~~~~~~~~!!   
*/

#include<iostream>
#include<map>
#include<list>
#include<queue>
#include<vector>
#include<algorithm>
#include<climits>

using namespace std;

#define int long long
#define lmax LLONG_MAX
#define lmin LLONG_MIN
#define pb push_back
#define mp make_pair
#define f   first
#define s   second    
#define vi   vector<int> 
#define vpii   vector<pair<int,int> >
#define varr   vector<int> v[1000000]
#define mii    map<int,int>
#define msi    map<string,int>
#define mlist  map<int,list>

#define wloop   int t\
               ;cin>>t\
               ;while(t--)
#define forxNi(x,n) for(int i=x;i<n;i++)
#define forxNj(x,n) for(int j=x;j<n;j++)
#define forNxi(n,x) for(int i=n;i>=x;i--)
#define forNxj(n,x) for(int j=n;j>=x;j--)

#define fastio ios_base::sync_with_stdio(0)\
               ;cin.tie(0)\
               ;cout.tie(0)

//------Code begins--->

int32_t main(){
	fastio;
	int n;
	cin>>n;
	int a[n],b[n],c[n];
	forxNi(0,n){
		cin>>a[i]>>b[i]>>c[i];
	}
	int dp[n][3];
	forxNi(0,n){
		forxNj(0,3){
			dp[i][j]=0;
		}
	}
	dp[0][0]=a[0];
	dp[0][1]=b[0];
	dp[0][2]=c[0];
	forxNi(1,n){
		dp[i][0]=a[i]+max(dp[i-1][1],dp[i-1][2]);
		dp[i][1]=b[i]+max(dp[i-1][0],dp[i-1][2]);
		dp[i][2]=c[i]+max(dp[i-1][1],dp[i-1][0]);
	}
	int maxim=lmin;
	forxNi(0,3){
		if(dp[n-1][i]>maxim)maxim=dp[n-1][i];
	}
	cout<<maxim;
	cout<<'\n';
	
	return 0;
}