//(bool) ? (if true) : (if false)
#include<bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(0);cin.tie(0)
#define fst first
#define snd second
#define all(x) (x).begin(), (x).end()
#define pb push_back
#define pf push_front
#define sz size()
#define FORN(i,j,n) for(long long i=j; i<(long long)n;i++) 
#define FOR(i,n) FORN(i,0,n)
#define FORIT(i,x) for( auto i = x.begin() ; i != x.end() ; i++ )
#define LIM 262150
#define ones(x) __builtin_popcount(x)
#define trace(x)    cerr << #x << ": " << x << endl;
#define trace2(x, y) cerr << #x << ": " << x << " | " << #y << ": " << y << endl;
using namespace std;
 
typedef long long ll ;
typedef unsigned long long ull ;
typedef vector <int> vi;
typedef vector <long long> vll;
typedef pair <int,int> ii;
typedef vector <string> vs;
typedef vector <ii> vii;
string cad1,cad2;
ll dp[3005][3005];
deque<char> ans;
int main() {
	fastio;
	cin>> cad1 >> cad2 ;
	FOR(i,cad1.sz+1){
		FOR(j,cad2.sz+1){
			if (i == 0 | j == 0){ dp[i][j] = 0; continue; }
            if(cad1[i-1] == cad2[j-1]){
			    dp[i][j] = dp[i-1][j-1] + 1;
			}			
			else{
				dp[i][j] = max(dp[i][j-1],dp[i-1][j]);
			}
		}
	}
	ll a = cad1.sz; 
	ll b = cad2.sz;
	while(a>0 && b>0){
		if(dp[a][b] == dp[a][b-1]) b--;
		else if(dp[a][b] == dp[a-1][b]) a--;
		else if(dp[a][b] == dp[a-1][b-1] + 1){
			ans.pf(cad1[a-1]); 
			a--; b--;
		}
	}
	FOR(i,ans.sz){
		cout<< ans[i] ;
	}
	cout<< '\n';
	return 0;
}