#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
typedef long long ll;
#define ALL(v) v.begin(), v.end()
#define vmax(v) *max_element(ALL(v))
#define vmin(v) *min_element(ALL(v))
#define chmax(x, a) x = max(x, a)
#define chmin(x, a) x = min(x, a)

int main() {
    int N; cin >> N;
    int ab = 0, a = 0, b = 0, cnt = 0;
    vector<string> s(N);
    rep(i, N) cin >> s[i];
    rep(i, N) {
        if (s[i][0] == 'B' && s[i][s[i].length()-1] == 'A') ab++;
        else if (s[i][0] == 'B') b++;
        else if (s[i][s[i].length()-1] == 'A') a++;
        rep(j, s[i].length()-1) {
            if (s[i][j] == 'A' && s[i][j+1] == 'B') cnt++;
        }
    }
    if (ab == 0) {
        cout << min(a, b) + cnt << endl;
        return 0;
    }
    if (a + b == 0) {
        cout << cnt + ab - 1 << endl;
    }
    else cout << cnt + min(a, b) + ab << endl;
}
