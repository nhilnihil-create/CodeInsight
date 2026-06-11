#include <algorithm>
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(), (x).end()
#define ll long long
#define INF 1000000000000000000

int main() {
    int N, K;
    cin >> N >> K;
    deque<ll> D;
    rep(i, N) {
        ll v;
        cin >> v;
        D.push_back(v);
    }

    ll ans = 0;

    for (int i = 0; i <= K; i++) {
        int a, b;
        for (int j = 0; j <= i; j++) {
            a = j;
            b = i - a;
            if (a + b > N)
                continue;
            priority_queue<ll, vector<ll>, greater<ll>> q;
            ll cnt = 0;
            rep(k, a) {
                if (k <= N - 1) {
                    cnt += D[k];
                    q.push(D[k]);
                }
            }

            rep(k, b) {
                if (N - 1 - k >= 0) {
                    cnt += D[N - 1 - k];
                    q.push(D[N - 1 - k]);
                }
            }

            int limit = K - i;
            while (limit > 0 && !q.empty()) {
                if (q.top() > 0)
                    break;
                cnt -= q.top();
                q.pop();
                limit--;
            }

            ans = max(ans, cnt);
        }
    }

    cout << ans << endl;
}