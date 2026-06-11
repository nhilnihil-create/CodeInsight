#include <bits/stdc++.h>
using namespace std;

using P = pair<long long, long long>;
//[l, r)
P separate2(int l, int r, const vector<long long> &sum) {
    long long m = (sum.at(r) - sum.at(l)) / 2;

    int ng = r;
    int ok = l;

    while (abs(ok - ng) > 1) {
        int mid = (ok + ng) / 2;

        if (m < sum.at(r) - sum.at(mid)) ok = mid;
        else ng = mid;
    }

    long long min_diff = 1e+15;
    int sep = ok;
    for (int i = -5; i <= 5; i++) {
        int ni = ok + i;
        if (l <= ni && ni < r) {
            long long d = abs((sum.at(r) - sum.at(ni)) - (sum.at(ni) - sum.at(l)));
            if (d < min_diff) {
                min_diff = d;
                sep = ni;
            }
        } 
    }

    return P(sum.at(r) - sum.at(sep), sum.at(sep) - sum.at(l));
}

int main() {
    int n;
    cin >> n;
    vector<long long> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a.at(i);
    }

    vector<long long> sum(n + 1);
    for (int i = 0; i < n; i++) {
        sum.at(i + 1) = sum.at(i) + a.at(i);
    }

    long long mini = 1e+15;
    for (int i = 2; i <= n - 2; i++) {
        P p1 = separate2(0, i, sum);
        long long p = p1.first, q = p1.second;
        P p2 = separate2(i, n, sum);
        long long r = p2.first, s = p2.second;

        mini = min(mini, max({p, q, r, s}) - min({p, q, r, s}));
    }

    cout << mini << endl;
}