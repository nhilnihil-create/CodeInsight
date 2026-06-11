#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main() {
    cin.tie(0); ios::sync_with_stdio(false);

    int n;
    cin >> n;
    vector<ll> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];

    vector<pair<int, int>> op;

    int min_idx = -1, max_idx = -1;
    for (int i = 0; i < n; ++i) {
        if (min_idx == -1 || a[i] < a[min_idx]) min_idx = i;
        if (max_idx == -1 || a[i] > a[max_idx]) max_idx = i;
    }

    if (abs(a[min_idx]) <= abs(a[max_idx])) {
        for (int i = 0; i < n; ++i)
            if (i != max_idx) op.emplace_back(make_pair(max_idx, i));
        op.emplace_back(make_pair(max_idx, max_idx));
        for (int i = 0; i + 1 < n; ++i)
            op.emplace_back(make_pair(i, i + 1));
    }
    else {
        for (int i = 0; i < n; ++i)
            if (i != min_idx) op.emplace_back(make_pair(min_idx, i));
        op.emplace_back(make_pair(min_idx, min_idx));
        for (int i = n - 1; 0 < i; --i)
            op.emplace_back(make_pair(i, i - 1));
    }

    cout << op.size() << '\n';
    for (const auto &it: op)
        cout << it.first + 1 << ' ' << it.second + 1 << '\n';

    return 0;
}
