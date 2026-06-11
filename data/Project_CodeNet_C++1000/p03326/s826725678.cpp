#include <bits/stdc++.h>
using namespace std;
/* typedef */
typedef long long ll;
typedef pair<int, int> pii;
/* constant */
const ll LINF = 1LL << 50;
/* global variables */
/* function */
/* main */
int main(){
    int N, M;
    cin >> N >> M;
    vector<vector<ll> > v(N, vector<ll>(3));
    for (int i = 0; i < N; i++) for (int j = 0; j < 3; j++) cin >> v[i][j];

    ll ans = -LINF;
    for (int b = 0; b < 8; b++) {
        vector<ll> sum(N);
        for (int i = 0; i < N; i++) {
            ll tmp = 0;
            for (int j = 0; j < 3; j++) {
                if (b & (1 << j)) tmp += v[i][j];
                else tmp -= v[i][j];
            }
            sum[i] = tmp;
        }
        sort(sum.begin(), sum.end(), greater<ll>());
        ans = max(ans, accumulate(sum.begin(), sum.begin() + M, 0LL));
    }
    cout << ans << '\n';
}
