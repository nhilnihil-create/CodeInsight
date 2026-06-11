#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for(int i = 0; i < (n); ++i)

typedef long long ll;
typedef pair<int, int> P;

const int MAX = 1e5 + 5;
const int INF = 1001001001;
const int MOD = 1e9 + 7;

int main(){
    int N, K;
    cin >> N >> K;

    vector<int> A(N);
    rep(i, N) cin >> A[i];

    vector<ll> sum(N + 1);
    rep(i, N) sum[i + 1] = sum[i] + A[i];

    vector<ll> B;
    rep(i, N + 1) {
        rep(j, i) B.push_back(sum[i] - sum[j]);
    }

    ll ans = 0;
    int M = B.size();
    vector<bool> available(M, true);
    for (int i = 60; i >= 0; --i) {
        int cnt = 0;
        rep(j, M) if (available[j] && B[j] >> i & 1) cnt++;
        if (K <= cnt) {
            ans += 1L << i;
            rep(j, M) {
                if (!(B[j] >> i & 1)) available[j] = false;
            }
        }
    }

    cout << ans << endl;
}