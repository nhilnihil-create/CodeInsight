#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using Compare = function<bool(int, int)>;

ll solve(int n, vector<int>& l, vector<int>& r, int hoge, set<int, Compare> idx1, set<int, Compare> idx2) {
    ll ans = 0;
    int pos = 0;
    for (int i = 0; i < n; i++) {
        int j;
        if (hoge == 0) j = *idx1.begin();
        else j = *idx2.begin();
        if (pos < l[j]) {
            ans += l[j] - pos;
            pos = l[j];
        } else if (pos > r[j]) {
            ans += pos - r[j];
            pos = r[j];
        }
        idx1.erase(j);
        idx2.erase(j);
        hoge = 1 - hoge;
    }
    ans += abs(pos);

    return ans;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    vector<int> l(n), r(n);
    for (int i = 0; i < n; i++) {
        cin >> l[i] >> r[i];
    }

    auto c1 = [&](const int& i1, const int& i2){return (l[i1] != l[i2]) ? l[i1] > l[i2] : i1 < i2;};
    auto c2 = [&](const int& i1, const int& i2){return (r[i1] != r[i2]) ? r[i1] < r[i2] : i1 < i2;};
    set<int, Compare> idx1(c1), idx2(c2);

    for (int i = 0; i < n; i++) {
        idx1.insert(i);
        idx2.insert(i);
    }
    cout << max(solve(n, l, r, 0, idx1, idx2), solve(n, l, r, 1, idx1, idx2)) << endl;
    return 0;
}
