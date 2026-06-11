#include <bits/stdc++.h>
using namespace std;

int main() {
    int A, B, Q;
    cin >> A >> B >> Q;
    vector<long long> s(A), t(B);
    for (int i = 0; i < A; ++i) {
        cin >> s[i];
    }
    for (int i = 0; i < B; ++i) {
        cin >> t[i];
    }

    sort(s.begin(), s.end());
    sort(t.begin(), t.end());
    while (Q--) {
        long long x;
        cin >> x;
        int sd = lower_bound(s.begin(), s.end(), x) - s.begin();
        int td = lower_bound(t.begin(), t.end(), x) - t.begin();
        vector<long long> ns, nt;
        if (sd != 0) ns.push_back(s[sd - 1]);
        if (sd != s.size()) ns.push_back(s[sd]);
        if (td != 0) nt.push_back(t[td - 1]);
        if (td != t.size()) nt.push_back(t[td]);

        // デバッグ
        /*
        cout << "ns: ";
        for (auto x : ns) cout << x << " ";
        cout << endl;
        cout << "nt: ";
        for (auto x : nt) cout << x << " ";
        cout << endl;
        */
        long long res = 10000000000000LL;
        for (auto ps : ns) {
            for (auto pt : nt) {
                // psとptが同じ側だったら、dist = max(abs(ps-x),abs(pt-x))
                // psとptが違う側だったら、dist = min(2*abs(ps-x) + abs(pt-x), abs(ps-x) + 2*abs(pt-x))
                if ((ps - x > 0) ^ (pt - x > 0)) {
                    res = min(res, min(2 * abs(ps - x) + abs(pt - x), 2 * abs(pt - x) + abs(ps - x)));
                } else {
                    res = min(res, max(abs(ps - x), abs(pt - x)));
                }
            }
        }
        cout << res << endl;
    }

    return 0;
}