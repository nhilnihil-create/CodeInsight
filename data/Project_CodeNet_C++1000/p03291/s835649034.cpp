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

const int maxn = 1e5+10, mod = 1e9+7;
vector<int>a(maxn);
string s;
int n;



int32_t main(){
	IOS
	cin >> s;
	n = s.length();
	s = '$' + s;
	
	a[0]=1;
	for(int i=1;i<maxn;i++){
		a[i]=a[i-1]*3%mod;
	}
	
	int l = 0 , r = 0 , A = 0 , C = 0;
	for(int i=1;i<=n;i++){
		r += s[i]=='?';
		C += s[i]=='C';
	}
	int ans = 0;
	for(int i=1;i<=n;i++){
		r -= s[i]=='?';
		C -= s[i]=='C';
		
		if( s[i] == 'B' || s[i] == '?' ){
			ans += ( l * a[l-1] % mod + A*a[l] % mod ) * ( r * a[r-1] % mod + C*a[r] % mod ) % mod;
			ans %= mod;
		}
		
		l += s[i]=='?';
		A += s[i]=='A';
	}
	
	cout << ans ;
	
	
	
	
}
 
/*
 * long long or int?
 * index out of bound? 
 * Tested on own test case?corner?
 * Make more general solution.
 * Read Read Read Read ....
 */
