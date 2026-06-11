#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; ++i)
using ll = long long;
using namespace std;
const int INF = 1e9;

int main() {
    string s;
    cin >> s;

    int cnt = 0;
    rep(i, s.size()) {
        if (s[i] == 'o')
            ++cnt;
    }

    cnt += 15 - s.size();

    if (cnt >= 8)
        cout << "YES";
    else
        cout << "NO";
    cout << endl;

    return 0;
}