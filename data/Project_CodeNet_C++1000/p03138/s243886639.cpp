#include<bits/stdc++.h>
#define int long long
#define endl '\n'
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define bug1( x ) {cerr << (#x) <<"="<< x << endl;}
#define bug2( x , y ) {cerr << (#x) <<"="<< (x) << "    " << (#y) << "="<< (y) << endl;}
#define bug3( x , y , z ) {cerr << (#x) <<"="<<(x) << "    " << (#y) <<"="<< (y) << "    " << (#z) <<"="<< (z) << endl;}
#define bug4( x , y , z , w) {cerr << (#x) <<"="<<(x) << "    " << (#y) <<"="<< (y) << "    " << (#z) <<"="<< (z) << "    " << (#w) <<"="<< w << endl;}
#define bug5( x , y , z , w ,p) {cerr << (#x) <<"="<<(x) << "    " << (#y) <<"="<< (y) << "    " << (#z) <<"="<< (z) << "    " << (#w) <<"="<< w << "    " << (#p) <<"="<< p << endl;}
#define bug6( x , y , z , w ,p , q) {cerr << (#x) <<"="<<(x) << "    " << (#y) <<"="<< (y) << "    " << (#z) <<"="<< (z) << "    " << (#w) <<"="<< w << "    " << (#p) <<"="<< p << "    " << (#q) <<"="<< q << endl;}
#define bugn( x , n ) {cerr << (#x) <<":";for(int i=0;i<n;i++)cerr << x[i] <<"  "; cerr << endl;}
#define bugnm( x , n , m ) {cerr << (#x)<<endl;for(int i=0;i<n;i++){cerr << "Row #" << i<< ":";for(int j=0;j<m;j++)cerr << x[i][j] << "   ";cerr << endl;}}
typedef long long ll;
typedef long double ld;
using namespace std;

const int maxn = 1e5+10;
int a[maxn],sum[41][2],dp[41][2],n,k;
int solve(int i,int bnd){
	if( i == -1 )return 0;
	int &ans = dp[i][bnd];
	if( ans != -1 )return ans;
	ans = 0;
	int cur = k >> i & 1;
	if( bnd ){
		for(int d=0;d<cur;d++){
			ans=max(ans,sum[i][d]+solve(i-1,0));
		}
		ans=max(ans,sum[i][cur]+solve(i-1,1));
	}else{
		for(int d=0;d<2;d++){
			ans=max(ans,sum[i][d]+solve(i-1,0));
		}
	}
	return ans;
}
int32_t main(){
	IOS
	cin>>n>>k;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	memset(sum,0,sizeof(sum));
	for(int bit=0;bit<41;bit++){
		for(int i=0;i<n;i++){
			int b = a[i] >> bit & 1;
			sum[bit][b^1]+=1LL<<bit;
		}
	}
	memset(dp,-1,sizeof(dp));
	cout<<solve(40,1);
 }
/*
 * long long or int?
 * index out of bound? 
 * Tested on own test case?corner?
 * Make more general solution.
 * Read Read Read Read ....
 */
