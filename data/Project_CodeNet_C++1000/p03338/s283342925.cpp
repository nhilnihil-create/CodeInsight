#include <bits/stdc++.h>
using namespace std;
using ll         = long long;
constexpr ll MOD = 1000000007;
#define REP(i, n) for (ll i = 0; i < (n); i++)
#define REP2(i, x, n) for (ll i = x; i < (n); i++)
#define PR(x) cout << (x) << "\n"
#define PS(x) cout << (x) << " "
const long long INF = numeric_limits<long long>::max();
int main() {
    ll N;
    string S;
    cin >> N >> S;

    ll count = 0;
    REP2(i, 1, N) {
        string s1 = S.substr(0, i);
        string s2 = S.substr(i, N - i);
        sort(s1.begin(), s1.end());
        sort(s2.begin(), s2.end());
        s1.erase(unique(s1.begin(), s1.end()), s1.end());
        s2.erase(unique(s2.begin(), s2.end()), s2.end());

        ll c = 0;
        REP(j, s1.size()) {
            if (s2.find(s1[j]) != std::string::npos) {
                c++;
            }
        }

        count = max(count, c);
    }

    PR(count);
    return 0;
}