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
    vector<int> A(N), B(N);
    vector<pair<int, int>> AB(N);
    REP(i, N) {
        cin >> A[i] >> B[i];
        AB[i] = make_pair(A[i] + B[i], i);
    }
    sort(ALL(AB));
    reverse(ALL(AB));
    ll ans = 0;
    REP(i, N) {
        int j = AB[i].second;
        if (i % 2 == 0) ans += A[j];
        else ans -= B[j];
    }
    cout << ans << endl;
}