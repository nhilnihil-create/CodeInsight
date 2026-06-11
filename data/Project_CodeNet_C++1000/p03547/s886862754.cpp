#include <bits/stdc++.h>
#define rep(i, n) for (ll i = 0; i < n; ++i)
typedef long long ll;
using namespace std;
const int INF = 1e9;

int main() {
    string s, t;
    cin >> s >> t;

    if (s == t)
        cout << "=";
    else if (s > t)
        cout << ">";
    else
        cout << "<";
    cout << endl;

    return 0;
}
