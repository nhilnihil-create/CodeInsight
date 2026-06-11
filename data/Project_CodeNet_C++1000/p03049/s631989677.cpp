#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
#define ALL(x) (x).begin(), (x).end()

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int N;
    cin >> N;
    vector<string> s(N);
    REP(i, N) cin >> s[i];
    int ans = 0, a = 0, b = 0, ab = 0;
    for (string st : s) {
        REP(i, st.size() - 1) {
            if (st[i] == 'A' && st[i+1] == 'B') ans++;
        }
        if (st[0] == 'B' && st[st.size() - 1] == 'A') ab++;
        else if (st[0] == 'B') b++;
        else if (st[st.size() - 1] == 'A') a++;
    }
    if (ab == 0) ans += min(a, b);
    else if (a == 0 && b == 0) ans += ab - 1;
    else if (a == 0 || b == 0) ans += ab;
    else ans += ab + 1 + min(a - 1, b - 1);
    cout << ans << endl;
}