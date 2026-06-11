#include <bits/stdc++.h>
#include <math.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
typedef long long ll;
using Graph = vector<vector<int>>;
typedef pair<int, int> P;

const int MOD = 1000000007;
const int INF_32 = 1LL << 30;
const int64_t INF_64 = 1LL << 60;

int main()
{
    int N, K;
    cin >> N >> K;
    vector<ll> V(N);
    ll ans = -INF_64;
    rep(i, N) cin >> V[i];

    for (int l = 0; l <= K; l++) {
        for (int r = 0; r <= K - l; r++) {
            if (l + r > N)
                continue;
            int d = K - l - r; // dump
            ll now = 0;
            vector<ll> neg;
            for (int i = 0; i <= l - 1; i++) {
                now += V[i];
                if (V[i] < 0) {
                    neg.push_back(V[i]);
                }
            }
            for (int i = 0; i <= r - 1; i++) {
                now += V[N - 1 - i];
                if (V[N - 1 - i] < 0) {
                    neg.push_back(V[N - 1 - i]);
                }
            }
            sort(neg.begin(), neg.end());
            int d_max = min(d, (int)neg.size());
            for (int i = 0; i < d_max; i++) {
                now -= neg[i];
            }
            ans = max(ans, now);
        }
    }
    cout << ans << endl;
    return 0;
}
// int main()
// {
//     int N, K;
//     cin >> N >> K;
//     vector<ll> V(N);
//     ll ans = -INF_64;
//     rep(i, N) cin >> V[i];
//     for (int c = 0; c <= K; c++) {
//         int a_max = min(K - c, N);
//         for (int a = 0; a <= a_max; a++) {
//             ll s = 0;
//             vector<ll> neg;
//             int b = K - c - a;
//             for (int i = 0; i < a; i++) {
//                 s += V[i];
//                 if (V[i] < 0) {
//                     neg.push_back(V[i]);
//                 }
//             }
//             for (int i = 0; i < min(b, N); i++) {
//                 s += V[N - i];
//                 if (V[N - i] < 0) {
//                     neg.push_back(V[N - i]);
//                 }
//             }
//             sort(V.begin(), V.end());
//             for (int i = 0; i < min((int)neg.size(), c); i++) {
//                 s -= neg[i];
//             }
//             ans = max(ans, s);
//         }
//     }
//     cout << ans << endl;

//     return 0;
// }
