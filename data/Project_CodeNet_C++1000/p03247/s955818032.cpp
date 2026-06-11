#include <iostream>
#include <algorithm>
#include <utility>
#include <vector>
#include <string>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
#define REP(i, n) for (int i = 0; i < (n); i++)
#define RREP(i, n) for (int i = (n) - 1; i >= 0; i--)
#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define RFOR(i, a, b) for (int i = (a); i > (b); i--)
#define ALL(a) (a).begin(), (a).end()

ll N, X[1000], Y[1000];

int main() {
    cin >> N;
    REP(i, N) cin >> X[i] >> Y[i];

    bool ok = true;
    REP(i, N - 1) {
        ok &= ((X[i] + Y[i] + 10000000000) % 2) == ((X[i + 1] + Y[i + 1] + 10000000000) % 2);
    }
    if (!ok) {
        cout << -1 << endl;
        return 0;
    }

    vector<int> d = {1};
    bool even = (X[0] + Y[0] + 10000000000) % 2 == 0;
    if (even) d.push_back(1);
    REP(i, 30) d.push_back(d[d.size() - 1] * 2);

    cout << d.size() << endl;
    for (int n : d) cout << n << " "; cout << endl;

    reverse(ALL(d));
    REP(i, N) {
        string ans = "";
        for (int n : d) {
            if (abs(X[i]) > abs(Y[i])) {
                if (X[i] > 0) {
                    ans += "R";
                    X[i] -= n;
                }
                else {
                    ans += "L";
                    X[i] += n;
                }
            }
            else {
                if (Y[i] > 0) {
                    ans += "U";
                    Y[i] -= n;
                }
                else {
                    ans += "D";
                    Y[i] += n;
                }
            }
        }
        reverse(ALL(ans));
        cout << ans << endl;
    }
    return 0;
}