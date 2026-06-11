#include <bits/stdc++.h>
#define fastIO (cin.tie(0), cout.tie(0), ios::sync_with_stdio(false))
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define precise(i) fixed << setprecision(i)
using namespace std;

double temperature(int T, int x) {
    return (double)T - (double)x * 0.006;
}

int main() {
    fastIO;
    int n, t, a;
    cin >> n >> t >> a;

    vector<int> H(n);
    rep(i, n) cin >> H.at(i);

    int pos = 0;
    double temp = 10000000.0;

    rep(i, n) {
        double diff = abs(temperature(t, H.at(i)) - (double)a);
        if (diff < temp) {
            temp = diff;
            pos = i;
        }
    }

    cout << pos + 1 << endl;
}
