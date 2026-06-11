#include <algorithm>
#include <cmath>
#include <vector>
#include <functional>
#include <cstdlib>
#include <map>
#include <set>
#include <iostream>
#include <string>
#include <ctype.h>
#include <climits>
#include <queue>
#include <iomanip>
using namespace std;
typedef long long ll;
#define REP(i, n) for(ll i = 0; i < (ll)(n); ++i)
template<class T> inline bool chmax(T& a, T b) { if(a < b){ a=b; return 1; } return 0;}
template<class T> inline bool chmin(T& a, T b) { if(a > b){ a=b; return 1; } return 0;}

const int maxn=100000;
int dp[maxn+1];

int main(){
	int n;
	cin >> n;
	
	const int INF=1<<20;
	
	REP(i,maxn+1) dp[i] = INF;
	
	dp[0] = 0;
	for(int i=0; i<=maxn; i++){
		chmin(dp[i+1], dp[i]+1);
		for(int j=6; i+j<=maxn; j*=6){
			chmin(dp[i+j], dp[i]+1);
		}
		for(int j=9; i+j<=maxn; j*=9){
			chmin(dp[i+j], dp[i]+1);
		}
	}
	
	cout << dp[n] << endl;
	
	return 0;
}