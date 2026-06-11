#include <bits/stdc++.h>
#define fastIO (cin.tie(0), cout.tie(0), ios::sync_with_stdio(false))
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define precise(i) fixed << setprecision(i)
using namespace std;

int main() {
    fastIO;
    int n;
    cin >> n;
    vector<int> L(n);
    rep(i, n) cin >> L.at(i);
    sort(L.begin(), L.end());

    int longest = L.back();
    int rest = 0;
    for (size_t i = 0; i < L.size() - 1; i++) {
        rest += L.at(i);
    }

    if (longest < rest)
        cout << "Yes";
    else
        cout << "No";
}