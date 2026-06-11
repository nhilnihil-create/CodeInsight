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
    int Cnt = 0;
    bool ok = true;
    if (s[0] != 'A')
        ok = false;
    for (int i = 0; i < s.length(); ++i) {
        char c = s[i];
        if (c != 'A' && c != 'C' && isupper(c)) {
            ok = false;
        }
        if (i >= 2 && i < s.length() - 1) {
            if (c == 'C') {
                ++Cnt;
            }
        }
    }
    if (Cnt != 1)
        ok = false;

    if (ok)
        cout << "AC" << endl;
    else
        cout << "WA" << endl;
    return 0;
}
