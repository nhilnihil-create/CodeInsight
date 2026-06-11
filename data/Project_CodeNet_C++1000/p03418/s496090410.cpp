#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<long long> vl;
#define INF __INT32_MAX__
#define LINF __LONG_LONG_MAX__

int main() {
    ll N, K;
    cin >> N >> K;

    if (K == 0) {
        cout << (N * N) << endl;
        return 0;
    }

    ll cnt = 0;
    for (int b = 1; b <= N; b++) {
        if (b <= K) continue;
        ll bcnt = 0;

        ll cycle = N / b;
        bcnt += cycle * (b - K);

        ll mod = N % b;
        if (mod >= K) {
            bcnt += mod + 1 - K;
        }
// cout << "b: " << b << ", cycle: " << cycle << ", mod: " << mod << ", bcnt: " << bcnt << endl;

        cnt += bcnt;
    }

    cout << cnt << endl;
}