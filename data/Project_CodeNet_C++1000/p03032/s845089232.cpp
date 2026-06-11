#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define sz(x) int(x.size())
using namespace std;
typedef long long ll;
typedef pair<int, int> P;

const ll INF = 1LL << 60;

int N, K;
vector<int> v;
int main() {
    cin >> N >> K;
    v.resize(N);
    rep(i, N) cin >> v[i];

    int ans = 0;
    // l と r　を決める
    for (int l = 0; l <= K; l++) {
    // for (int l = 2; l <= 2; l++) {
        // l + r <= N - 1
        for (int r = 0; l + r <= K; r++) {
            if (l + r > N) continue;
        // for (int r = 1; r <= 1; r++) {
            // 戻せる数 (小さい順に戻す)
            int d = max(0, K - l - r);

            // cout << l << " " << r << " " << d << endl;

            // 範囲を決めて取り出す 
            vector<int> tmp;
            int now = 0;
            // 左から l 個
            for (int j = 0; j < l; j++) {
                tmp.push_back(v[j]);
                now += v[j];
            }
            // cout << l << " " << now << endl;

            // 右から r 個
            for (int j = 0; j < r; j++) {
                tmp.push_back(v[N - 1 - j]);
                now += v[N - 1 - j]; 
            }
            // cout << r << " " << now << endl;
            // cout << l << " " << r << " " << now << endl;

            // 戻す
            sort(tmp.begin(), tmp.end());

            for (int j = 0; j < d; j++) {
                if (j >= tmp.size()) break;
                if (tmp[j] > 0) break;
                now -= tmp[j];
            }
            // cout << l << " " << r << " " << now << endl;
            // rep(i, tmp.size()) {
            //     cout << tmp[i] << " "; 
            // }
            // cout <<endl;

            ans = max(ans, now);
        }
    }

    cout << ans << endl;
}