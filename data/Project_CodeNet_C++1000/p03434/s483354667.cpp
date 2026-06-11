#include <bits/stdc++.h>
#define fastIO (cin.tie(0), cout.tie(0), ios::sync_with_stdio(false))
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define precise(i) fixed << setprecision(i)
using lint = long;
using llint = long long;
using namespace std;

int main() {
    fastIO;
    int n;
    cin >> n;
    vector<int> a(n);
    rep(i, n) cin >> a.at(i);
    sort(a.begin(), a.end());
    reverse(a.begin(), a.end());

    int total = 0;
    for (size_t i = 0; i < a.size(); i++) {
        if (i % 2 == 0)
            total += a.at(i);
        else
            total -= a.at(i);
    }
    cout << total << endl;
}
