#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<long long> vl;
#define INF __INT32_MAX__
#define LINF __LONG_LONG_MAX__

int main() {
    ll N, H;
    cin >> N >> H;
    vl A(N), B(N);
    ll amax = 0;
    rep(i, N) {
        cin >> A[i] >> B[i];
        amax = max(amax, A[i]);
    }

    vl bv;
    rep(i, N) {
        if (B[i] > amax) {
            bv.push_back(B[i]);
        }
    }
    sort(bv.begin(), bv.end());
    reverse(bv.begin(), bv.end());

    ll cnt = 0;
    rep(i, bv.size()) {
        H -= bv[i];
        cnt++;
        if (H <= 0) break;
    }
    if (H > 0) {
        cnt += (H / amax);
        if (H % amax != 0) cnt++;
    }

    cout << cnt << endl;
}