//(bool) ? (if true) : (if false)
#include<bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(0);cin.tie(0)
#define fst first
#define snd second
#define all(x) (x).begin(), (x).end()
#define pb push_back
#define sz size()
#define FORN(i,j,n) for(long long i=j; i<(long long)n;i++) 
#define FOR(i,n) FORN(i,0,n)
#define FORIT(i,x) for( auto i = x.begin() ; i != x.end() ; i++ )
#define MOD 998244353LL
#define LIM 262150
#define ones(x) __builtin_popcount(x)
#define trace(x)    cerr << #x << ": " << x << endl;
#define trace2(x, y) cerr << #x << ": " << x << " | " << #y << ": " << y << endl;
using namespace std;
 
typedef long long ll ;
typedef unsigned long long ull ;
typedef vector <int> vi;
typedef pair <int,int> ii;
typedef vector <string> vs;
typedef vector <ii> vii;
ll n;
double arr[3005];
double dp[3005][3005];
double ans = 0.0;
int main() {
	fastio;
	cin>> n;
	FORN(i,1,n+1) cin>> arr[i];
	
	FORN(i,1,n+1){
		FOR(j,i+1){
			if(i == 1){
				dp[1][j] = (j == 1) ? arr[1] : (1-arr[1]);
				continue;
			}
			dp[i][j] = dp[i-1][j]*(1-arr[i]) + dp[i-1][j-1]*(arr[i]);
		}
	}
	FORN(i,(n/2+1),n+1){
		ans += dp[n][i];
	}
	cout.precision(10);
	cout<< ans << '\n';
	return 0;
}