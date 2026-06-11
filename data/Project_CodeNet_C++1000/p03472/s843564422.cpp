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
    ll amax = -1;
    rep(i, N) {
        cin >> A[i] >> B[i];
        amax = max(amax, A[i]);
    }

    priority_queue<ll> pq;
    rep(i, N) {
        if (B[i] > amax) {
            pq.push(B[i]);
        }
    }

    ll cnt = 0;
    while (!pq.empty()) {
        if (H <= 0) break;
        ll b = pq.top(); pq.pop();
        H -= b;
        cnt++;
    }

    if (H > 0) {
        cnt += H / amax;
        if (H % amax != 0) cnt++;
    }

    cout << cnt << endl;
}