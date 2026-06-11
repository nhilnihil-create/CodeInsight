#include<bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(0);cin.tie(0)
#define fst first
#define snd second
#define all(x) (x).begin(), (x).end()
#define pb push_back
#define sz size()
#define FORN(i,j,n) for(int i=j; i<(int)n;i++) 
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
ll n,k;
ll arr[100005];
ll dp[100005];
int main() {
	fastio;
	cin>> n >> k;
	FOR(i,n) cin>> arr[i];
	FOR(i,k+1){
	    FOR(j,n){
			if(i >= arr[j]){
				dp[i] = max(dp[i],1-dp[i-arr[j]]);
			}
		}
	}
	if(dp[k] == 1) cout<< "First\n";
	else cout<< "Second\n";
	return 0;
}