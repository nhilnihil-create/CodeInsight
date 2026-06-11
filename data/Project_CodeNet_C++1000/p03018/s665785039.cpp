#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
#define ALL(x) (x).begin(), (x).end()

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    string s;
    cin >> s;
    int A = 0, B = 0;
    ll ans = 0;
    REP(i, s.size()) {
        if (s[i] == 'A') {
            if (B == 0) A++;
            else {
                B = 0;
                A = 1;
            }
        }
        if (s[i] == 'B') {
            if (B == 0 && A > 0) B++;
            else if (B == 1) A = 0;
        }
        if (s[i] == 'C') {
            if (B == 0) A = 0;
            else {
                B = 0;
                ans += A;
            }
        }
    }
    cout << ans << '\n';
}