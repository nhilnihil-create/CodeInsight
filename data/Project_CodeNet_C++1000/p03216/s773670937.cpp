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
    string S;
    cin >> S;
    int Q;
    cin >> Q;
    vector<int> k(Q);
    REP(i, Q) cin >> k[i];

    for (int l : k) {
        ll D = 0, M = 0, tmp = 0, ans = 0;
        REP(i, N) {
            if (i >= l) {
                if (S[i-l] == 'D') {
                    tmp -= M;
                    D--;
                }
                if (S[i-l] == 'M') M--;
            }
            if (S[i] == 'D') D++;
            if (S[i] == 'M') {
                M++;
                tmp += D;
            }
            if (S[i] == 'C') ans += tmp;
        }
        cout << ans << '\n';
    }
}