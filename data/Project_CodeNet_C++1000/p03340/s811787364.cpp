#include <bits/stdc++.h>
#define REP(i, s, n) for (int i = s; i < n; i++)
using namespace std;
typedef long long ll;

int main() {
    int N; cin >> N;
    vector<int> A(N);
    REP(i, 0, N) cin >> A[i];

    int r = 0; ll ans = 0, sum = 0;
    REP(l, 0, N) {
        while (r < N && (sum + A[r]) == (sum ^ A[r])) {
            sum += A[r++];
        }
        ans += r - l;
        if (l == r) r++;
        else sum -= A[l];
    }

    cout << ans << endl;
    return 0;
}