#include <bits/stdc++.h>
#define rep(i, n) for (ll i = 0; i < n; ++i)
using ll = long long;
using namespace std;
const int INF = 1e9;

int main() {
    string s, t;
    cin >> s >> t;

    sort(s.begin(), s.end());
    sort(t.rbegin(), t.rend());

    s < t ? cout << "Yes" : cout << "No";
    cout << endl;

    return 0;
}