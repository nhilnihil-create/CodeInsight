#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i=0; i<n; i++)
#define pb push_back
#define int long long
typedef pair<int, int> P;

int N, M;
vector<P> AB;

signed main() {
    cin.tie(0); ios::sync_with_stdio(false);
    cin >> N >> M;
    rep(i, N) {
        int A, B; cin >> A >> B;
        AB.pb(P(A, B));
    }
    sort(AB.begin(), AB.end());
    int ans = 0;
    rep(i, N) {
        int A = AB[i].first, B = AB[i].second;
        if (M-B>0) {
            ans += B*A;
            M -= B;
        }
        else {
            ans += M*A;
            break;
        }
    }
    cout << ans << endl;
}