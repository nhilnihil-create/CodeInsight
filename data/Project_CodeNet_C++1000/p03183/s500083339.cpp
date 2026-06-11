#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;
using vll = vector<ll>;
using vvll = vector<vll>;
using vb = vector<bool>;
using vd = vector<double>;
using vs = vector<string>;

constexpr int MAX_SOLID = 10000;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;

    vector<tuple<int, int, ll> > blocks(N);
    for(int i=0;i<N;i++){
        int w, s;
        ll v;
        cin >> w  >> s >> v;
        blocks[i] = make_tuple(-(s+w), w, v);
    }

    sort(blocks.begin(), blocks.end());

    vll dprow(MAX_SOLID+1, 0);
    vvll dp(N, dprow);

    for(int i=0;i<N;i++){
        int cs = -get<0>(blocks[i]);
        int cw = get<1>(blocks[i]);
        ll cv = get<2>(blocks[i]);

        cs -= cw;

        // cout << cs << " " << cw << " " << cv << endl;

        dp[i][cs] = max(dp[i][cs], cv);

        if (i > 0) {
            for(int c=0; c<=MAX_SOLID; c++) {
                dp[i][c] = max(dp[i][c], dp[i-1][c]);
            }

            for(int c=cw; c<=MAX_SOLID; c++){
                int nc = min(c-cw, cs);
                dp[i][nc] = max(dp[i][nc], dp[i-1][c] + cv);
            }
        }

        for (int c=MAX_SOLID-1; c>=0; c--) {
            dp[i][c] = max(dp[i][c], dp[i][c+1]);
        }
    }

    ll ans = 0;
    for(int c=0;c<=MAX_SOLID;c++) ans = max(ans, dp[N-1][c]);
    cout << ans << endl;

    return 0;
}