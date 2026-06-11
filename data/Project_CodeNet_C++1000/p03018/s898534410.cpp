#include <bits/stdc++.h>
using namespace std;
using ll = long long;

constexpr int inf = 0x3f3f3f3f;
constexpr ll linf = 0x3f3f3f3f3f3f3f3fLL;

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);

    string s; cin >> s;
    int n = s.length();

    vector<int> v;
    for (int i = 0; i < n; i++) {
        if (s[i] == 'A') {
            v.push_back(1);
        } else if (i < n - 1 && s[i] == 'B' && s[i + 1] == 'C') {
            v.push_back(0); i++;
        } else {
            v.push_back(inf);
        }
    }
    int m = v.size();

    ll ans = 0;
    int zero = 0;
    int i = 0;
    while (i < m) {
        int j = i;
        while (j < m && v[j] < inf) j++;
        for (int k = i; k < j; k++) {
            if (v[k] == 0) zero++;
        }
        for (int k = i; k < j; k++) {
            if (v[k] == 1) ans += zero;
            if (v[k] == 0) zero--;
        }
        i = j + 1;
    }
    cout << ans << endl;
    return 0;
}
