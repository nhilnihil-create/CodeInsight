
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

string s;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> s;
    int n = s.length();
    int ans = 1e9;
    for (int i = 0; i < n - 2; ++i) {
        ans = min(ans, abs(753 - (s[i] - '0') * 100 - (s[i + 1] - '0') * 10 - (s[i + 2] - '0')));
    }
    cout << ans << endl;

    return 0;
}

