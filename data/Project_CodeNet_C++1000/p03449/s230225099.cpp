#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < n; i++)
#define repr(i, n) for (int i = n-1; i >= 0; i--)
#define ALL(x) x.begin(), x.end()
using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
const int mod = 1e9+7;
const int INF = 1e9;
const int MAX = 1e6;

int main() {
    int n;
    cin >> n;
    vector<int> a1(n), a2(n);
    rep(i, n) {
        cin >> a1[i];
    }
    rep(i, n) {
        cin >> a2[i];
    }
    vector<int> s1(n+1), s2(n+1);
    rep(i, n+1) {
        if (i == 0) {
            s1[i] = s2[i] = 0;
        } else {
            s1[i] = s1[i-1] + a1[i-1];
            s2[i] = s2[i-1] + a2[i-1];
        }
    }
    int ans = 0;
    rep(i, n+1) {
        if (i == 0) continue;
        int cnt = 0;
        cnt += s1[i] - s2[0];
        cnt += s2[n] - s2[i-1];
        ans = max(ans, cnt);
    }
    cout << ans << endl;
}