#include <bits/stdc++.h>
using namespace std;
using ll         = long long;
constexpr ll MOD = 1000000007;
#define REP(i, n) for (ll i = 0; i < (n); i++)
#define REP2(i, x, n) for (ll i = x; i < (n); i++)
const long long INF = numeric_limits<long long>::max();
int main() {
    string str;
    cin >> str;
    vector<ll> num(4);
    for (ll i = 0; i < 4; ++i) {
        num[i] = str[i] - '0';
#ifdef SOURCE_TEST
        cout << num[i] << "\n";
#endif
    }
    for (ll i = 0; i < 1U << 3; ++i) {
        ll sum = num[0];
        for (ll j = 0; j < 3; ++j) {
            if (i & (1U << j)) {
#ifdef SOURCE_TEST
                cout << sum << "+=" << num[j + 1] << "\n";
#endif
                sum += num[j + 1];
            } else {
#ifdef SOURCE_TEST
                cout << sum << "-=" << num[j + 1] << "\n";
#endif
                sum -= num[j + 1];
            }
        }
#ifdef SOURCE_TEST
        cout << "ans==" << sum << endl;
#endif
        if (sum == 7) {
            cout << num[0];
            for (ll j = 0; j < 3; ++j) {
                if (i & (1U << j)) {
                    cout << "+";
                } else {
                    cout << "-";
                }
                cout << num[j + 1];
            }
            cout << "=7\n";
            break;
        }
    }

    return 0;
}