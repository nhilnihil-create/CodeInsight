#include <bits/stdc++.h>
using namespace std;
using i64 = int64_t;
using vi = vector<i64>;
using vvi = vector<vi>;

class BIT {
    int n;
    vi data0, data1;

    void add(vi& data, int i, i64 x) {
        while (i <= n) {
            data[i] += x;
            i += i & -i;
        }
    }

    i64 sum(vi& data, int i) {
        i64 s = 0;
        while (i > 0) {
            s += data[i];
            i -= i & -i;
        }
        return s;
    }

public:
    BIT(int n) : n(n) {
        data0 = vi(n + 1);
        data1 = vi(n + 1);
    }

    // [l, r)
    void add(int l, int r, i64 x) {
        l++;
        r++;
        add(data0, l, -x * (l - 1));
        add(data1, l, x);
        add(data0, r, x * (r - 1));
        add(data1, r, -x);
    }

    // [l, r)
    i64 sum(int l, int r) {
        i64 s = 0;
        s += sum(data0, r) + sum(data1, r) * r;
        s -= sum(data0, l) + sum(data1, l) * l;
        return s;
    }
};

int check(vi as, int s, int k, int q) {
    int n = as.size();
    vi dpl(n), dpr(n);

    using ii = pair<int, int>;
    vector<ii> vs;
    for (int i = 0; i < n; i++) {
        if (as[i] >= s) {
            vs.push_back(ii(as[i], i));
        }
    }
    sort(vs.begin(), vs.end());

    for (int i = 1; i < n; i++) {
        if (as[i - 1] >= s) {
            dpl[i] = dpl[i - 1] + 1;
        } else {
            dpl[i] = 0;
        }
    }
    for (int i = n - 2; i >= 0; i--) {
        if (as[i + 1] >= s) {
            dpr[i] = dpr[i + 1] + 1;
        } else {
            dpr[i] = 0;
        }
    }
    
    vi dp(n);
    for (int i = 0; i < n; i++) {
        if (as[i] >= s) {
            dp[i] = dpl[i] + dpr[i] + 1;
        } else {
            dp[i] = 0;
        }
    }

    BIT bit(n);
    for (int i = 0; i < n; i++) {
        bit.add(i, i + 1, dp[i]);
    }

    int cnt = 0;
    i64 nax = 0;
    for (ii& v: vs) {
        int a = v.first;
        int i = v.second;

        if (bit.sum(i, i + 1) >= k) {
            bit.add(i - dpl[i], i, -1);
            bit.add(i, i + dpr[i] + 1, -1);
            cnt++;
            nax = max(nax, as[i]);
            if (cnt == q) {
                return nax - s;
            }
        }
    }
    return -1;
}

int main() {
    int n, k, q;
    cin >> n >> k >> q;
    vi as(n);
    for (int i = 0; i < n; i++) {
        cin >> as[i];
    }

    vi bs(as);
    sort(bs.begin(), bs.end());

    int nin = 1e9;
    for (int b: bs) {
        int res = check(as, b, k, q);
        if (res != -1) {
            nin = min(nin, res);
        }
    }

    cout << nin << endl;
}