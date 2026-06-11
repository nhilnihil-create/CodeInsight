#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
typedef long long ll;
typedef vector<vector<int>> vv;
typedef pair<int, int> P;

// input
int N, M;
vector<int> A, B;


void input() {
    cin >> N >> M;
    A = B = vector<int>(N);
    rep(i, N) cin >> A[i] >> B[i];
}


int main() {
    input();
    vector<P> w(N);
    rep(i, N) w[i] = P(A[i], B[i]);
    sort(w.begin(), w.end());
    ll ans = 0;
    int m = M;
    rep(i, N) {
        if (m <= w[i].second) {
            ans += ll(w[i].first) * m;
            break;
        } else {
            ans += ll(w[i].first) * w[i].second;
            m -= w[i].second;
        }
    }
    cout << ans << endl;
}
