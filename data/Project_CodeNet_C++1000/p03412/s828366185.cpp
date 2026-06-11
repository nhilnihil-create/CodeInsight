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

int main() {
    int N, A[200000], B[200000], B_mod[200000];
    cin >> N;
    REP(i, N) cin >> A[i];
    REP(i, N) cin >> B[i];
    
    int ans = 0;
    REP(k, 29) {
        REP(i, N) B_mod[i] = B[i] % (1 << (k + 1));
        sort(B_mod, B_mod + N);

        int count = 0;
        REP(i, N) {
            int a_mod = A[i] % (1 << (k + 1));
            count += lower_bound(B_mod, B_mod + N, ((1 << k) * 2) - a_mod)
                   - lower_bound(B_mod, B_mod + N, ((1 << k)    ) - a_mod);
            count += lower_bound(B_mod, B_mod + N, ((1 << k) * 4) - a_mod)
                   - lower_bound(B_mod, B_mod + N, ((1 << k) * 3) - a_mod);
        }
        ans |= (count & 1) << k;
    }
    cout << ans << endl;
    return 0;
}