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

struct cusum {
    int n;
    vector<ll> s;
    cusum(vector<int> &a) {
        n = (int)a.size();
        s.resize(n+1);
        s[0] = 0;
        for (int i = 1; i <= n; i++) {
            s[i] = s[i-1] + a[i-1];
        }
    }
    ll sum(int a, int b) { // 閉区間[a,b]の和
        return s[b+1] - s[a];
    }
};

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
    // vector<int> s1(n+1), s2(n+1);
    // rep(i, n+1) {
    //     if (i == 0) {
    //         s1[i] = s2[i] = 0;
    //     } else {
    //         s1[i] = s1[i-1] + a1[i-1];
    //         s2[i] = s2[i-1] + a2[i-1];
    //     }
    // }
    cusum s1(a1), s2(a2);
    int ans = 0;
    rep(i, n) {
        int cnt = 0;
        // cnt += s1[i] - s2[0];
        // cnt += s2[n] - s2[i-1];
        cnt += s1.sum(0, i);
        cnt += s2.sum(i, n-1);
        ans = max(ans, cnt);
    }
    cout << ans << endl;
}