#include <bits/stdc++.h>
#define rep(i, n) for (ll i = 0; i < n; ++i)
typedef long long ll;
using namespace std;
const int INF = 1e9;

int main() {
    string s;
    cin >> s;

    if (s[0] == s[1] && s[1] == s[2])
        cout << "Yes";
    else if (s[1] == s[2] && s[2] == s[3])
        cout << "Yes";
    else
        cout << "No";
    cout << endl;

    return 0;
}
