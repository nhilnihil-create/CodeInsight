#include <bits/stdc++.h>
#define REP(i, s, n) for (int i = s; i < n; i++)
using namespace std;
typedef long long ll;

int main() {
    int N; cin >> N;

    ll ans = 0; int a = 0, b = 0, ab = 0;
    REP(i, 0, N) {
        string s; cin >> s;
        REP(j, 0, s.size() - 1) {
            if (s[j] == 'A' && s[j + 1] == 'B') ans++;
        }
        if (s.front() == 'B' && s.back() == 'A') ab++;
        else if (s.front() == 'B') b++;
        else if (s.back() == 'A') a++;
    }
    
    if (ab > 0) {
        ans += (ab - 1);
        if (a > 0) {
            ans++;
            a--;
        }
        if (b > 0) {
            ans++;
            b--;
        }
    }

    ans += min(a, b);
    cout << ans << endl;

    return 0;
}