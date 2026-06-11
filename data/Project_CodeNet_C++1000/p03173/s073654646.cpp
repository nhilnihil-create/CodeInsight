// Program.cpp

#include <bits/stdc++.h>
using namespace std;

typedef long long           ll;
typedef pair<int, int>      pii;
typedef vector<int>         vi;

#define fr(i, n)            for(int i=0; i<(n); ++i)
#define frC(i, n)           for(int i=0; (i<(n)) && (c); ++i)
#define frA(i, a, n)        for(int i=a; i<=(n); ++i)
#define frD(i, a, n)        for(int i=a; i>=(n); --i)
#define fill(a)             memset(a, 0, sizeof(a))
#define revsort(a, b)       sort(a, b, greater<int>())
#define dout                if(DEBUGGING) cout
#define dbg                 if(DEBUGGING) 
#define endl                "\n"

int DEBUGGING    =          0;
const int INF    =          1000000000;
const int MOD    =          1000000007;
const double PI  =          3.1415926535897932;
const double EPS =          1e-7;

void solve(int TEST_CASE){
    int n;
    cin >> n;
    ll dp[n+1][n];
    ll cost[n+1][n];
    //dp[i][j] -> minimum possible sum of size i and starting index j
    fr(i,n){
    	dp[0][i] = 0;
    	cin >> dp[1][i];
    	cost[1][i] = 0;
    	cost[0][i] = 0;
    }

    for(int i=2;i<=n;++i){
    	for(int j=0;j<=n-i;++j){
    		ll p = 1e18;
    		ll q;
    		for(int k=1;k<=i-1;++k){
    			q = dp[k][j] + dp[i-k][j+k];
    			if(q<p)
    				p = q;
    		}
    		dp[i][j] = p;
    	}
    }
    for(int i=2;i<=n;++i){
    	for(int j=0;j<=n-i;++j){
    		ll p = 1e18;
    		ll q;
    		for(int k=1;k<=i-1;++k){
    			q = cost[k][j] + dp[k][j] + cost[i-k][j+k] + dp[i-k][j+k];
    			if(q<p)
    				p = q;
    		}
    		cost[i][j] = p;
    	}
    }
    cout << cost[n][0] << endl;
}

int main(int argc, char* argv[]){
    if(argc==2 && argv[1][1]=='v') DEBUGGING = 1;
    cin.sync_with_stdio(0);
    cin.tie(0);
    cin.exceptions(cin.failbit);
    int nTestCases=1;
    //cin >> nTestCases;
    frA(i,1,nTestCases) solve(i);
    return 0;
}