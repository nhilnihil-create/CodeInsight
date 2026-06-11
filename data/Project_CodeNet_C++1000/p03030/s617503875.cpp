#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = 1LL << 60;

int main() {
    int n;
    cin >> n;
    vector<tuple<string, int, int>> a(n);
    for (int i = 0; i < n; i++) {
        cin >> get<0>(a[i]) >> get<1>(a[i]);
        get<1>(a[i]) = -get<1>(a[i]);
        get<2>(a[i]) = i + 1;
    }
    sort(a.begin(), a.end());
    for (int i = 0; i < n; i++) {
        cout << get<2>(a[i]) << endl;
    }
    return 0;
}