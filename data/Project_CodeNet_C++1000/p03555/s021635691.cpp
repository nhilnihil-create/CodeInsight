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

string s, t;
int main() {
    cin >> s >> t;
    if (s[0] != t[2] || s[1] != t[1] || s[2] != t[0])
        cout << "NO" << endl;
    else
        cout << "YES" << endl;
    return 0;
}
