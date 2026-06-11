#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define sz(x) int(x.size())
using namespace std;
typedef long long ll;
typedef pair<int, int> P;

const ll INF = 1LL << 60;

ll N;
vector<ll> C, S, F;

int main() {
    cin >> N;
    C.resize(N - 1);
    S.resize(N - 1);
    F.resize(N - 1);

    rep(i, N - 1) cin >> C[i] >> S[i] >> F[i];

    // シュミレーション
    rep(i, N - 1) {
        ll time = 0;

        // スタート地点
        time += S[i];
        time += C[i];

        // 移動
        for (int j = i + 1; j < N - 1; j++) {
            // 達してない場合はまつ
            if (time < S[j]) {
                time += S[j] - time;
            } else if (time % F[j] == 0) {
                // 何もしない
            } else{
                // 待ち時間がる場合はたす
                time += F[j] - (time % F[j]);
            }

            time += C[j];
        }

        cout << time << endl;
    }
    cout << 0 << endl;
}