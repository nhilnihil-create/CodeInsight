#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = 1LL << 60;
ll MOD = 1000000000 + 7;

int main() {
    string s, t;
    cin >> s >> t;
    sort(s.begin(), s.end());
    sort(t.begin(), t.end(), greater<int>());
    string ans = "No";
    if (s < t) ans = "Yes";
    cout << ans << endl;
    return 0;
}