#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;
#define chmax(x,y) x = max(x,y);

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> v(n);
    rep(i,n) cin >> v[i];
    int ans = 0;
    for (int l = 0; l <= k; l++) {
        for (int r = 0; r <= k-l; r++) {
            if (l+r > n) continue;
            int d = k-l-r;
            int now = 0;
            vector<int> s;
            for (int i = 0; i < l; i++) {
                now += v[i];
                s.push_back(v[i]);
            }
            for (int i = n-r; i <= n-1; i++) {
                now += v[i];
                s.push_back(v[i]);
            }
            sort(s.begin(), s.end());
            rep(i,d) {
                if (i >= s.size()) break;
                if (s[i] > 0) break;
                now -= s[i];
            }
            ans = max(ans, now);
        }
    }
    cout << ans << endl;
    return 0;
}