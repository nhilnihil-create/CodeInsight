#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mod=1e9+7;
int dp[22][1<<22];

int solve(vector<vector<int > >& grid, int row, int womenAvailable, int N) {
    if(row > N) {
        if(womenAvailable) return 0;
        else return 1;
    }

    if(dp[row][womenAvailable] != -1) return dp[row][womenAvailable];

    int ans = 0;
    for(int col=0; col<N; col++) {
        if(grid[row][col+1] && ((1<<col) & womenAvailable) ) {
            ans = (ans + solve(grid, row+1, ((1<<col) ^ womenAvailable), N))%mod;
        }
    }
    return dp[row][womenAvailable] = ans;
}

int32_t main() {
    int N; cin>>N;
    vector<vector<int > > grid(N+1, vector<int> (N+1));
    for(int i=1; i<=N; i++) {
        for(int j=1; j<=N; j++) {
            int tmp; cin>>tmp;
            grid[i][j] = tmp;
        }
    }
    memset(dp, -1, sizeof dp);
    cout<<solve(grid, 1, (1<<N)-1 , N)<<endl;
    return 0;
}
