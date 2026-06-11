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
    int n=0;
    int N,M;
    cin >> N >> M;
    char grid[N][M];
    fr(i,N){
    	fr(j,M){
    		cin >> grid[i][j];
    	}
    }
    int dp[N+1][M+1];
    //dp[i][j] -> no. of ways to reach block {i,j}
    fr(i,N+1){
        fr(j,M+1)
            dp[i][j] = 0;
    }

    dp[1][1] = 1;
    frA(i,1,N){
        frA(j,1,M){
            if(grid[i-1][j-1] == '#')
                dp[i][j] = 0;
            else{
                dp[i][j] = (dp[i][j] + dp[i-1][j] + dp[i][j-1])%(1000000007);
            }
        }
    }
    cout << dp[N][M] << endl;
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