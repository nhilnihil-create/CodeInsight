#include <bits/stdc++.h>
#define fastIO (cin.tie(0), cout.tie(0), ios::sync_with_stdio(false))
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define precise(i) fixed << setprecision(i)
using lint = long;
using llint = long long;
using namespace std;

int main() {
    fastIO;
    int n, d, x;
    cin >> n >> d >> x;
    vector<int> A(n);
    rep(i, n) cin >> A.at(i);

    int cnt = 0;
    rep(i, n) {
        int part = A.at(i);
        int weight = 0;
        rep(day, d) {
            if (d >= part * weight + 1)
                cnt++;
            weight++;
        }
    }
    cout << cnt + x << endl;
}
