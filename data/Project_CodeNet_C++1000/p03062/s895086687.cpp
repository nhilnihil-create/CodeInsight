#include <bits/stdc++.h>
using namespace std;

#define rep(i, a) for (int i = 0; i < (a); i++ )
#define FOR(i, m, n) for(int i = m; i < n; i++)

typedef pair<int,int> P;
typedef long long ll;

const int INF = 1001001001;
const int MOD = 1000000007;
const double PI=acos(-1);

int main(){
    ll N;
    cin >> N;
    ll A[N];
    rep(i,N) {
        ll a;
        cin >> a;
        A[i] = a;
    }
    vector<vector<ll>> dp(N,vector<ll>(2,-1e15));

    dp[1][0] = A[0]+A[1];
    dp[1][1] = -dp[1][0];
    rep(i,N-1) {
        if (i==0) continue;
        dp[i+1][0] = max(dp[i][0]+A[i+1],dp[i][1]+A[i+1]);
        dp[i+1][1] = max(dp[i][0]-A[i+1]-2*A[i],dp[i][1]-A[i+1]+2*A[i]);
    }

    cout << max(dp[N-1][0],dp[N-1][1]) << endl;
}
