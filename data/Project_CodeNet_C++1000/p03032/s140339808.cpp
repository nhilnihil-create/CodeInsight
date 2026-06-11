#include <algorithm>
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(), (x).end()
#define ll long long
#define ld long double
#define INF 1000000000000000000
typedef pair<ll, ll> pll;
typedef pair<int, int> pint;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int N, K;
    cin >> N >> K;
    vector<ll> d(N);
    rep(i, N) { cin >> d[i]; }

    ll ans = 0;

    for (int i = 0; i <= N; i++) {
        for (int j = 0; j <= N; j++) {
            // 左からi個、右からj個。　
            if (i + j > N)
                continue;
            if (i + j > K)
                continue;
            int nokori = K - i - j;
            deque<ll> v;
            for (int k = 0; k < i; k++) {
                v.push_back(d[k]);
            }

            for (int l = N - 1; l > N - 1 - j; l--) {
                v.push_back(d[l]);
            }

            sort(all(v));
            while (!v.empty() && v.front() < 0 && nokori > 0) {
                v.pop_front();
                nokori--;
            }

            ll tmp = accumulate(all(v), (ll)0);
            ans = max(ans, tmp);
        }
    }

    cout << ans << endl;
}