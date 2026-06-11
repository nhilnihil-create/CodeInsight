#include <bits/stdc++.h>

using namespace std;

const int max_n = 1011, inf = 1000111222;

long long mabs(long long x) {
    if (x < 0) {
        return -x;
    }
    return x;
}

int n;
long long x[max_n], y[max_n];
int f[2];

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> x[i] >> y[i];
        f[(((x[i] + y[i]) % 2) + 2) % 2] = 1;
    }
    if (f[0] + f[1] == 2) {
        cout << -1 << endl;
        return 0;
    }
    vector<long long> all;
    if (f[0]) {
        all.push_back(1);
    }
    for (int i = 33; i >= 0; --i) {
        all.push_back(1LL << i);
    }
    cout << all.size() << endl;
    for (long long x : all) {
        cout << x << " ";
    }
    cout << endl;
    if (f[0]) {
        all.erase(all.begin());
    }
    for (int i = 0; i < n; ++i) {
        long long sum = accumulate(all.begin(), all.end(), 0LL);
        if (f[0]) {
            cout << 'R';
            --x[i];
        }
        for (long long a : all) {
            sum -= a;
            if (mabs(x[i] - a) + mabs(y[i]) <= sum) {
                cout << 'R';
                x[i] -= a;
            } else if (mabs(x[i] + a) + mabs(y[i]) <= sum) {
                cout << 'L';
                x[i] += a;
            } else if (mabs(x[i]) + mabs(y[i] - a) <= sum) {
                cout << 'U';
                y[i] -= a;
            } else if (mabs(x[i]) + mabs(y[i] + a) <= sum) {
                cout << 'D';
                y[i] += a;
            } else {
                exit(228);
            }
        }
        cout << endl;
    }
    return 0;
}
