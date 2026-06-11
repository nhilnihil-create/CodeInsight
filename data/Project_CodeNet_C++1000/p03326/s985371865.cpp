#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
 
int main() {
	cin.tie(0);
    ios::sync_with_stdio(false);

    int N, M;
    cin >> N >> M;

    vector<vector<ll> > A(N, vector<ll>(3));

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < 3; j++) {
            cin >> A[i][j];
        }
    }

    if(M == 0) {
        cout << 0 << endl;
        return 0;
    }

    ll ans = 0;

    for(int i = 0; i < 8; i++) {

        vector<vector<ll> > dp(N, vector<ll>(M));
        vector<ll> s(N);

        for(int j = 0; j < 3; j++) {
            if(i & (1 << j)) {
                dp[0][0] -= A[0][j];
                s[0] -= A[0][j];
            } else {
                dp[0][0] += A[0][j];
                s[0] += A[0][j];
            }
        }

        for(int j = 1; j < N; j++) {

            ll c = 0;
            for(int k = 0; k < 3; k++) {
                if(i & (1 << k))
                    c -= A[j][k];
                else
                    c += A[j][k];
            }

            s[j] = c;

            if(c > dp[j - 1][0])
                dp[j][0] = c;
            else
                dp[j][0] = dp[j - 1][0];

            for(int k = 1; k < min(j + 1, M); k++) {
                c = dp[j - 1][k - 1] + s[j];
                if(c > dp[j - 1][k] || j == k)
                    dp[j][k] = c;
                else
                    dp[j][k] = dp[j - 1][k];
            }
        }

        ans = max(ans, dp[N - 1][M - 1]);
/*
        for(int j = 0; j < N; j++) {
            for(int k = 0; k < M; k++) {
                cerr << dp[j][k] << " ";
            }
            cerr << endl;
        }
        cerr << endl;*/
    }

    cout << ans << endl;
}