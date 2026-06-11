#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
typedef long long ll;
using namespace std;

int main() {
    string s, ns;
    cin >> s;

    ll a = 0, cnt = 0;
    rep(i, s.size() - 1) {
        if (s[i] == 'B' && s[i + 1] == 'C') {
            cnt += a;
            i++;
        } else if (s[i] == 'A')
            a++;
        else
            a = 0;
    }

    cout << cnt << endl;
    return 0;
}
