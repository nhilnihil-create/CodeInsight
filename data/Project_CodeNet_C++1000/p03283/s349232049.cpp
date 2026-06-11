#include <bits/stdc++.h>
 
using namespace std;
 
using usize = ::std::size_t;
using u64 = ::std::int_least64_t;
//using u64 = int;
static constexpr u64 Inf = ::std::numeric_limits<u64>::max() / 2;


int main(int argc, char *argv[])
{
    
 
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int N, M, Q;
    cin >> N >> M >> Q;
    vector<int> low(N+2, 0), up(N+2,0);
    vector<vector<int>> dp(N+2, vector<int>(N + 2, 0)),dp_buffer(N+2, vector<int>(N + 2, 0));
    for (int i = 1; i <= M; i++) {
        int L, R;
        cin >> L >> R;
        dp_buffer[L][R]++;
        dp[L][R]++;
    }
    
    for (int i = 0; i <= N+1; i++) {
        for (int j = i; j <= N+1; j++) {
            if(!dp_buffer[i][j]) continue;
            for (int ii = 0; ii <= i; ii++) {
                for (int jj = j; jj <= N+1; jj++) {
                    if(ii == i && jj == j) continue;
                    dp[ii][jj] += dp_buffer[i][j];
                }
            }
        }
    }
    
    while (Q--) {
        int p, q;
        cin >> p >> q;
        cout << dp[p][q] << endl;
    }
    
    return 0;
    
}
