#include <bits/stdc++.h>

#define rep(i, n) for(int i = 0; i<(n); i++)
#define chmax(x, y) x = max(x, y)
#define chmin(x, y) x = min(x, y)
using namespace std;
typedef long long ll;

typedef pair<int, int> P;

int INF = 100100100;

int main() {
    int N;
    cin >> N;
    vector<P> R(N);
    vector<P> B(N);
    rep(i, N) cin >> R[i].first >> R[i].second;
    rep(i, N) cin >> B[i].first >> B[i].second;

    sort(R.begin(), R.end());
    sort(B.begin(), B.end());

    int ans = 0;
    vector<bool> used(N, false);
    rep(i, N) {
        int r_index = -1;
        int max_height = -1;
        rep(j, N) {
            if (used[j]) continue; // この赤い点は使用済み
            if (R[j].first < B[i].first && R[j].second < B[i].second && max_height < R[j].second) {
                r_index = j;
                max_height = R[j].second;
            }
        }

        if (r_index != -1) {
            ans++;
            used[r_index] = true;
        }
    }

    cout << ans << endl;
}
