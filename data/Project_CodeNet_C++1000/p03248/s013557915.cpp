#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using pli = pair<ll, int>;
using pil = pair<int, ll>;
using uint = unsigned int;
template <typename T>
using Graph = vector<vector<T>>;
const int MOD = 998244353;
const ld PI = acosl(-1);

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    string s;
    cin >> s;
    int n = s.length();

    bool isok = true;
    if (s.back() == '1' || s[0] == '0')
        isok = false;

    vector<int> v(n);
    for (int i = 0; i < n; ++i) {
        v[i] = n - i - 1;
        if (i < n - 1 && s[i] != s[n - i - 2])
            isok = false;
    }

    if (!isok)
        cout << -1 << '\n';
    else {
        vector<bool> finished(n);
        int pos = 1;
        for (int i = 0; i < n; ++i) {
            if (finished[i] || s[i] == '0')
                continue;
            while (pos < i + 1) {
                cout << pos << " " << i + 1 << '\n';
                pos++;
            }
            finished[i] = finished[n - i - 2] = true;
        }
        cout << pos << " " << pos + 1 << endl;
        pos++;
        for (int i = pos + 1; i <= n; ++i)
            cout << pos << " " << i << '\n';
    }

    return 0;
}
