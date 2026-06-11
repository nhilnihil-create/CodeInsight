#define rep(i, n) for (int i = 0; i < (n); i++)
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int, int>;
const int MOD = 1000000007;

int main() {
    string s, t;
    cin >> s >> t;

    sort(s.begin(), s.end());
    sort(t.begin(), t.end(), greater<char>());

    string ans = (s < t) ? "Yes" : "No";

    cout << ans << endl;

    return 0;
}
