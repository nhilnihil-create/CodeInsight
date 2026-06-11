#pragma GCC target ("avx2")
#pragma GCC optimize ("unroll-loops")
#pragma GCC optimize ("O3")
#include "bits/stdc++.h"
#include <unordered_set>
#include <unordered_map>
#include <random>
using namespace std;
typedef long long ll;
const ll MOD = 1'000'000'007LL; /*998'244'353LL;*/
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()
#define rep(i, n) for(int (i)=0; (i)<(n); (i)++)
const int dx[4]={ 1,0,-1,0 };
const int dy[4]={ 0,1,0,-1 };

int N, Z, W;
int A[2005];

int dp[2005][2];
int solve(int n, int t){
    if(dp[n][t] != -1) return dp[n][t];
    if(t == 0){
        int ret = abs(A[n-1] - A[N]);
        for(int i=n; i<N; i++){
            ret = max(ret, solve(i+1, t^1));
        }
        return dp[n][t] = ret;
    }
    else{
        int ret = abs(A[n-1] - A[N]);
        for(int i=n; i<N; i++){
            ret = min(ret, solve(i+1, t^1));
        }
        return dp[n][t] = ret;
    }
}

signed main(){
    cin >> N >> Z >> W;
    A[0] = W;
    rep(i, N) cin >> A[i+1];

    memset(dp, -1, sizeof(dp));
    cout << solve(1, 0) << endl;
}