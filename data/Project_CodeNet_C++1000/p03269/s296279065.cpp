#include <bits/stdc++.h>
using namespace std;
using i64 = int64_t;
using vi = vector<i64>;
using vvi = vector<vi>;

struct edge {
    int s, t, w;
};

int main() {
    int l;
    cin >> l;
    int n = 1, t = 0;;
    for (; n <= l; n <<= 1, t++);
    n >>= 1, t--;
    if (n == l) {
        cout << t + 1 << " " << 2 * t << endl;
        for (int i = 1; i <= t; i++) {
            cout << i << " " << i + 1 << " " << 0 << endl;
            cout << i << " " << i + 1 << " " << (1 << (i - 1)) << endl;
        }
        return 0;
    }

    cout << t + 1 << " ";
    vector<edge> es;
    for (int i = 1; i <= t; i++) {
        es.push_back({i, i + 1, 0});
        es.push_back({i, i + 1, (1 << (i - 1))});
    }

    vi as;
    for (int i = 0; i < t; i++) {
        as.push_back(1 << i);
    }

    auto ikamax = [&](i64 a) {
        if (upper_bound(as.begin(), as.end(), a) - lower_bound(as.begin(), as.end(), a)) {
            return a;
        } else {
            int d = lower_bound(as.begin(), as.end(), a) - as.begin();
            return as[d - 1];
        }
    };

    auto get_beki = [&](i64 a) {
        int cnt = 0;
        while (a > 1) {
            a >>= 1;
            cnt++;
        }
        return cnt;
    };

    int made = n;
    while (made < l) {
        int k = ikamax(l - made);
        es.push_back({get_beki(k) + 1, t + 1, made});
        made += k;
    }

    cout << es.size() << endl;
    for (edge& e: es) {
        cout << e.s << " " << e.t << " " << e.w << endl;
    }
}
