#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define sz(x) int(x.size())
using namespace std;
typedef long long ll;
typedef pair<int, int> P;

const ll INF = 1LL << 60;

ll N;

int main() {
    cin >> N;

    ll ans = INF; 
    for (ll i = 1; i <= N - 1; i++) {
        string A = to_string(i);
        string B = to_string(N - i);

        ll tmp = 0;
        rep(j, A.size()) {
            tmp += A[j] - '0';
        }

        rep(j, B.size()) {
            tmp += B[j] - '0';
        }
        ans = min(ans, tmp);
    }
    cout << ans << endl;
}