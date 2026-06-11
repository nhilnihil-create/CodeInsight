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

const int N = 1e5 + 5;
int n, m, k, ans;
string s;

int main() {
    cin >> s;
    n = s.length();
    for (int i = 0; i < n; ++i) {
        if (s[i] == '1') {
            s[i] = '9';
        } else if (s[i] == '9') {
            s[i] = '1';
        }
    }
    cout << s << endl;
    return 0;
}
