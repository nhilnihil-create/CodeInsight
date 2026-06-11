
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

string s, t;
bool ok;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> s >> t;
    int n = s.length();
    for (int i = 0; i < n; ++i) {
        int idx = i;
        ok = true;
        for (int j = 0; j < n; ++j) {
            if (s[idx] != t[j]) {
                ok = false;
                break;
            }
            idx = (idx + 1) % n;
        }
        if (ok)
            break;
    }
    if (ok)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;

    return 0;
}

