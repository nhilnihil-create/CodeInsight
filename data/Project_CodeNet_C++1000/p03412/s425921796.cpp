#include <bits/stdc++.h>

#define REP(i,n) for (int i=0;i<(n);++i)
#define all(a) (a).begin(),(a).end()

using namespace std;

using ll = long long;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    const int M = 28; // a, b < pow(2, 28)
    int N;
    cin >> N;
    vector<int> a(N), b(N);
    REP(i, N) cin >> a[i];
    REP(i, N) cin >> b[i];

    int result = 0;
    REP(j, M + 1) {
        int mask = (1 << j) - 1;
        vector<int> masked_b(N);
        REP(i, N) {
            masked_b[i] = b[i] & mask;
        }
        sort(all(masked_b));
        if (N % 2 == 1) {
            REP(i, N) {
                result ^= a[i] & 1 << j;
                result ^= b[i] & 1 << j;
            }
        }
        ll carry = 0;
        REP(i, N) {
            int not_a = (~a[i]) & mask;
            carry += distance(lower_bound(all(masked_b), not_a + 1), masked_b.end());
        }
        if (carry % 2 == 1) {
            result ^= 1 << j;
        }
    }
    cout << result << endl;
    return 0;
}