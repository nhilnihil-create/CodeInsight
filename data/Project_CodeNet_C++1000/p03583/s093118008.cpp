#include <bits/stdc++.h>
#define REP(i, s, n) for (int i = s; i < (int)(n); i++)
#define ALL(a) a.begin(), a.end()
#define MOD 1000000007
using namespace std;
using ll = long long;

int main() {
    ll N; cin >> N;

    for (ll h = 1; h < 3501; h++) {
        for (ll n = 1; n < 3501; n++) {
            if (4 * h * n - N * n - N * h <= 0) continue;
            if (N * h * n % (4 * h * n - N * n - N * h) == 0) {
                cout << h << " " << n << " " << N * h * n / (4 * h * n - N * n - N * h) << endl;
                return 0;
            }
        }
    }
    return 0;
}