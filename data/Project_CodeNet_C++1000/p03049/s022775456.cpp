#include <bits/stdc++.h>
#define rep(i, n) for (ll i = 0; i < n; i++)
using ll = long long;
using namespace std;
const int INF = 1e9;

int numToDig(int a) {
    return to_string(a).size();
}

int main() {

    int N, ans = 0, a = 0, b = 0, ab = 0;
    cin >> N;
    rep(i, N) {
        string S;
        cin >> S;
        rep(i, S.size()) {
            if (strncmp(&S[i], "AB", 2) == 0)
                ans++;
        }
        if (S[0] == 'B' && S[S.size() - 1] == 'A')
            ab++;
        else if (S[0] == 'B')
            b++;
        else if (S[S.size() - 1] == 'A')
            a++;
    }

    if (ab == 0)
        ans += min(a, b);
    else if (a + b > 0)
        ans += ab + min(a, b);
    else if (a + b == 0)
        ans += ab - 1;

    cout << ans << endl;

    return 0;
}