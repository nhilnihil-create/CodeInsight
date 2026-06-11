#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    sort(a.begin(), a.end());
    vector<pair<int, int>> Q(m);
    for (int i = 0; i < m; i++) cin >> Q[i].second >> Q[i].first;
    sort(Q.begin(), Q.end());
    int ind = m - 1;
    vector<int> d;
    for (int i = 0; i < n; i++) {
        Q[ind].second--;
        d.push_back(Q[ind].first);
        if (Q[ind].second == 0) ind--;
        if (ind == -1) break;
    }
    for (int i = 0; i < n && i < d.size(); i++) {
        if (a[i] >= d[i]) break;
        a[i] = d[i];
    }
    long long sum = 0;
    for (auto i: a) sum += i;
    cout << sum << endl;
    return 0;
}