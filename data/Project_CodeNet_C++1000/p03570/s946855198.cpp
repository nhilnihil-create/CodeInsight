#include<bits/stdc++.h>
//#define int long long
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

const int maxn = 2e5+10;
int msk[maxn],dp[maxn],n;
int mp[1<<26];
string s;
int32_t main(){
	IOS
	cin >> s;
	n = s.length();
	msk[0]=0;
	for(int i=1;i<=n;i++){
	   msk[i]=msk[i-1] ^ 1<<(s[i-1]-'a');
	}
	for(int i=0;i<1<<26;i++){
		mp[i]=1e8;
	}
	mp[0] = 0;
	for(int i=1;i<=n;i++){
		dp[i] = i;
		dp[i] = min( dp[i], mp[msk[i]] + 1);
		for(int j = 0 ; j < 26; j++ ){
			int cur = msk[i] ^ 1 << j;
			dp[i] = min( dp[i] , mp[cur] + 1);
		}
		if( mp[ msk[i] ] > dp[i] ){
			mp[ msk[i] ] = dp[i];
		}
	}
	cout << dp[n];
		
	
	
}
/*
 * long long or int?
 * index out of bound? 
 * Tested on own test case?corner?
 * Make more general solution.
 * Read Read Read Read ....
 */
