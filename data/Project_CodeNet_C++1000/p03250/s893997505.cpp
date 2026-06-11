#include <bits/stdc++.h>
#define fastIO (cin.tie(0), cout.tie(0), ios::sync_with_stdio(false))
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define precise(i) fixed << setprecision(i)
using namespace std;

int main() {
    fastIO;
    vector<int> in;
    rep(i, 3) {
        int t;
        cin >> t;
        in.push_back(t);
    }
    sort(in.begin(), in.end());
    cout << (in.at(2) * 10 + in.at(1) + in.at(0));
}