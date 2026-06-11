#include <algorithm>
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(), (x).end()
#define ll long long
#define INF 100000000000000000

int main() {
    string s;
    cin >> s;
    vector<bool> use(26, false);
    rep(i, s.size()) {
        int n = s[i] - 'a';
        use[n] = true;
    }

    if (s.size() != 26) {
        rep(i, 26) {
            if (!use[i]) {
                s += (char)(i + 'a');
                break;
            }
        }
        cout << s << endl;
    } else {
        int cnt = 0;
        string ss = s;
        string ns;
        do {
            cnt++;
            ns = s;
            if (cnt == 2)
                break;
        } while (next_permutation(all(s)));

        if (ns == ss) {
            cout << -1 << endl;
            return 0;
        }

        rep(i, s.size()) {
            if (ss[i] == ns[i])
                cout << ns[i];
            else {
                cout << ns[i];
                break;
            }
        }
    }
}