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

    for (int a = 0; a <= N; a++) {
        for (int b = 0; b <= N; b++) {
            if (a + b <= N && a + b <= K) {
                ll cnt = 0;
                vector<ll> v;
                rep(i, a) {
                    cnt += D[i];
                    v.push_back(D[i]);
                }

                rep(j, b) {
                    cnt += D[N - 1 - j];
                    v.push_back(D[N - 1 - j]);
                }

                sort(all(v));

                // 捨てる操作は最大でK-a-b回できる。-のやつは捨てられるだけ捨てよう
                rep(k, K - a - b) {
                    if (k >= v.size())
                        continue;
                    if (v[k] < 0)
                        cnt -= v[k];
                }

                ans = max(ans, cnt);
            }
        }
    }

    cout << ans << endl;
}