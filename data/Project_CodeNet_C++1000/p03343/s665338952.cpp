#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define chmax(a, b) a = max(a, b)
#define chmin(a, b) a = min(a, b)
#define all(x) (x).begin(), (x).end()
using namespace std;
using ll = long long;
using P = pair<int,int>;
using VI = vector<int>;
using VVI = vector<VI>;

int main() {
    int n, k, q;
    cin >> n >> k >> q;
    VI a(n), ta;
    rep(i, n) cin >> a[i];
    ta = a;
    sort(all(ta));
    ta.erase(unique(all(ta)), ta.end());
    int ans = 1001001001;
    vector<bool> discarded(n, false);
    rep(i, ta.size()) {
        int l = 0;
        priority_queue<int, VI, greater<int>> p, cur_p;
        rep(r, n) {
            if (discarded[r]) {
                int cnt = max(0, r - l - k + 1);
                while(cnt-- && !cur_p.empty()) {
                    p.push(cur_p.top());
                    cur_p.pop();
                }
                while(!cur_p.empty()) cur_p.pop();
                l = r + 1;
            } else {
                cur_p.push(a[r]);
            }
        }
        int cnt = max(0, n - l - k + 1);
        while(cnt-- && !cur_p.empty()) {
            p.push(cur_p.top());
            cur_p.pop();
        }
        if (p.size() < q) {
            break;
        }
        int mn, mx;
        mn = p.top(); p.pop();
        mx = mn;
        rep(_, q - 1) {
            mx = p.top(); p.pop();
        }
        chmin(ans, mx - mn);
        rep(j, n) if (a[j] == ta[i]) discarded[j] = true;
    }
    cout << ans << endl;
}