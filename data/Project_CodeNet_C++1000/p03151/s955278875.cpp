#include <bits/stdc++.h>
#define REP(i, s, n) for (int i = s; i < n; i++)
#define ALL(a) a.begin(), a.end()
#define MOD 1000000007
using namespace std;
typedef long long ll;

int main() {
    int N; cin >> N;
    vector<int> A(N), diff(N);
    REP(i, 0, N) cin >> A[i];
    REP(i, 0, N) {
        int b; cin >> b;
        diff[i] = A[i] - b;
    }

    sort(ALL(diff));
    int ans = 0;
    ll negative = 0;
    REP(i, 0, N) {
        if (diff[i] >= 0) break;
        negative += diff[i];
        ans++;
    }

    for (int i = diff.size() - 1; i >= 0; i--) {
        if (negative >= 0 || diff[i] <= 0) break;
        negative += diff[i];
        ans++;
    }

    if (negative < 0) {
        cout << -1 << endl;
    } else {
        cout << ans << endl;
    }
    return 0;
}