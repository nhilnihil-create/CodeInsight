#include <algorithm>
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(), (x).end()
#define ll long long
#define INF 1000000000000000000
typedef pair<ll, ll> pll;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    string s, t;
    cin >> s >> t;
    for (int i = s.size() - 1; i > -1; i--) {
        string ss1 = s.substr(0, i);
        string ss2 = s.substr(i);
        string ss3 = ss2 + ss1;
        if (ss3 == t) {
            cout << "Yes" << endl;
            return 0;
        }
    }

    cout << "No" << endl;
    return 0;
}