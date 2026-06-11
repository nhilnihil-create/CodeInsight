//#define _GLIBCXX_DEBUG
#include<bits/stdc++.h>

using namespace std;


const long long INF = 1e12;

void solve() {
    int A, B, Q; cin >> A >> B >> Q;
    vector<long long> s(A);
    vector<long long> t(B);

    for (int i = 0; i < A; i++) cin >> s[i];
    for (int i = 0; i < B; i++) cin >> t[i];

    sort(s.begin(), s.end());
    sort(t.begin(), t.end());

    for (int q = 0; q < Q; q++) {
        long long x; cin >> x;

        long long s_right, s_left, t_right, t_left;

        if (lower_bound(s.begin(), s.end(), x) == s.end()) {
            s_left = *(lower_bound(s.begin(), s.end(), x) - 1);
            s_right = INF;
        }
        else if (lower_bound(s.begin(), s.end(), x) == s.begin()) {
            s_left = -INF;
            s_right = *lower_bound(s.begin(), s.end(), x);
        } else {
            s_left = *(lower_bound(s.begin(), s.end(), x) - 1);
            s_right = *lower_bound(s.begin(), s.end(), x);
        }

        if (lower_bound(t.begin(), t.end(), x) == t.end()) {
            t_left = *(lower_bound(t.begin(), t.end(), x) - 1);
            t_right = INF;
        }
        else if (lower_bound(t.begin(), t.end(), x) == t.begin()) {
            t_left = -INF;
            t_right = *lower_bound(t.begin(), t.end(), x);
        } else {
            t_left = *(lower_bound(t.begin(), t.end(), x) - 1);
            t_right = *lower_bound(t.begin(), t.end(), x);
        }

        long long ans = min(x - t_left, x - s_left) + abs(t_left - s_left);
        ans = min(ans, min(t_right- x, s_right - x) + abs(t_right - s_right));
        ans = min(ans, min(t_right- x, x - s_left) + abs(t_right - s_left));
        ans = min(ans, min(x - t_left, s_right - x) + abs(t_left - s_right));

        cout << ans << endl;
    }
}


int main() {
    solve();
    return 0;
}