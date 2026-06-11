#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;
typedef pair<int, int> ii;
#define DEBUG freopen("in.txt", "r", stdin);

struct fastio {
    fastio() {
        ios::sync_with_stdio(false);
        cout << setprecision(10) << fixed;
        cin.tie(0);
    }
};

fastio _fast_io;

string s;
int main() {
    cin >> s;
    bool ok = false;
    if (s[0] == s[1] && s[1] == s[2])
        ok = true;
    if (s[2] == s[3] && s[1] == s[2])
        ok = true;
    if (ok)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;

    return 0;
}
