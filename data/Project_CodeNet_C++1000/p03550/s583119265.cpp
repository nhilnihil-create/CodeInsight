#include <bits/stdc++.h>

using namespace std;

const long long MOD = 1000000007LL;
long long GCD(long long a, long long b){return b == 0 ? a : GCD(b, a % b);}
long long fast_exp(long long base, long long exp, long long mod = MOD) {
    long long tot = 1;
    for(;exp > 0;exp >>= 1) {
       if((exp & 1) == 1) tot = tot * base % mod;
       base = base * base % mod;
    }
    return tot;
}

int arr[2003], dp[2003][2003][2];

int helper(int pos, int p1, int p2, int turn = 0){

    if(pos <= 0) return abs(arr[p1] - arr[p2]);

    if(dp[p1][p2][turn] != -1)
        return dp[p1][p2][turn];

    if(turn == 0){
        int best = max(helper(pos - 1, pos - 1, p2, 0), helper(pos - 1, p1, pos - 1, 1));
        dp[p1][p2][turn] = best;
        return best;
    } else {
        int best = min(helper(pos - 1, pos - 1, p2, 0), helper(pos - 1, p1, pos - 1, 1));
        dp[p1][p2][turn] = best;
        return best;
    }

}

int main(){

    cin.sync_with_stdio(0); cin.tie(0); cout.tie(0);

    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    //

    int n, z, w; cin >> n >> z >> w;

    for(int i = 0; i < n; ++i)
        cin >> arr[n - i - 1];

    for(int i = 0; i < 2003; ++i)
        for(int j = 0; j < 2003; ++j)
            dp[i][j][0] = dp[i][j][1] = -1;

    arr[n] = w;
    arr[n + 1] = z;


    cout << helper(n + 1, n + 1, n) << "\n";

    return 0;

}
