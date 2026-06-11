#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;
typedef pair<int, int> ii;

struct fastio {
    fastio() {
        ios::sync_with_stdio(false);
        cout << setprecision(10) << fixed;
        cin.tie(0);
    }
};

fastio _fast_io;


int n;
string s, t;
int m[26];
int main() {
    cin >> s >> t;
    n = s.length();
    for (int i = 0; i < 26; ++i) {
        m[i] = i;
    }
    for (int i = 0; i < n; ++i) {
        char o = s[i] - 'a';
        char real = m[o];
        char tar = t[i] - 'a';
        if (real != tar) {
            for (int j = 0; j < 26; ++j) {
                if (m[j] == real) {
                    m[j] = tar;
                } else if (m[j] == tar) {
                    m[j] = real;
                }
            }
        }
    }
    for (int i = 0; i < n; ++i) {
        char real = m[s[i] - 'a'];
        if (real != t[i] - 'a') {
            cout << "No" << endl;
            exit(0);
        }
    }
    cout << "Yes" << endl;
    return 0;
}
