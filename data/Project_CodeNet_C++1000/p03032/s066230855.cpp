#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0, i##_len = (n); i < i##_len; ++i)
#define reps(i, n) for (int i = 1, i##_len = (n); i <= i##_len; ++i)
#define rrep(i, n) for (int i = ((int)(n)-1); i >= 0; --i)
#define rreps(i, n) for (int i = ((int)(n)); i > 0; --i)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
#define repc2(i, s, n) for (int i = (s); i <= (int)(n); i++)
#define inf 2e9
#define linf 9000000000000000000ll
#define all(v) v.begin(), v.end()
using namespace std;
typedef long long ll;

int n, k;
vector<int> dq;

int main() {
    cin >> n >> k;
    dq.resize(n);
    rep(i, n) { cin >> dq[i]; }
    int ans = 0;
    rep(l, n + 1) {
        rep(r, n - l + 1) {
            if (l + r > k) break;
            priority_queue<int, vector<int>, greater<int>> pq;
            int sum = 0;
            rep(i, l) {
                sum += dq[i];
                pq.push(dq[i]);
            }
            rep(i, r) {
                sum += dq[n - 1 - i];
                pq.push(dq[n - 1 - i]);
            }
            int cd = k - l - r;
            rep(i, cd) {
                if (!pq.empty() && pq.top() < 0) {
                    sum -= pq.top();
                    pq.pop();
                } else {
                    break;
                }
            }
            ans = max(ans, sum);
        }
    }
    cout << ans << endl;
    return 0;
}