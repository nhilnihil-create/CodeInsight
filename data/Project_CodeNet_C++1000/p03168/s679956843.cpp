#include <iostream>
#include <set>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>
#include <string>
#include <stack>
#include <cmath>
#include <cstring>
#include <climits>
#include <iomanip>
using namespace std;

#define FORN(i, j, k) for(int i=j;i<k;i++)
#define FORR(i, j, k) for(int i=j;i>=k;i--)
#define REP(i, n) FORN(i, 0, n)
#define int long long
#define pii pair<int, int>
#define vi vector<int>
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define endl '\n'

const int MODO = 1e+9 + 7;
const int MAX = 1e+5 + 5;

int n;

void solve(){
	double p[n];
	REP(i,n){
		cin >> p[i];
	}
	double dp[n+1][n+1];
	dp[0][0] = 1;
	FORN(i, 1, n+1){
		dp[0][i] = 0;
	}
	
	FORN(i, 1, n+1){
		dp[i][0] = dp[i-1][0]*(1-p[i-1]);
	}
	
	FORN(i, 1, n+1){
		FORN(j, 1, n+1){
			dp[i][j] = dp[i-1][j-1]*p[i-1];
			dp[i][j] += dp[i-1][j]*(1-p[i-1]);
		}
	}
	
	double res=0;
	FORN(i, 1, n+1){
		int t=n-i;
		if(i>t){
			res+=dp[n][i];
		}
	}
	
	cout << std::setprecision(10 ) << res << endl;  
	return;
}

int32_t main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n;
	solve();
	return 0;
}
