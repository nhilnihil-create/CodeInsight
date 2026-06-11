#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ld = long double;

int main() {
    cin.tie(0); ios::sync_with_stdio(false);
    // cout << setprecision(8) << setiosflags(ios::fixed);

    vector<int> cnt(10);
    for (int i = 0, n; i < 4; ++i) {
        cin >> n;
        ++cnt[n];
    }

    if (cnt[1] && cnt[4] && cnt[7] && cnt[9])
        cout << "YES\n";
    else
        cout << "NO\n";

    return 0;
}
