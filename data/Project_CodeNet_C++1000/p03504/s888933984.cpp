#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<long long> vl;
typedef vector<bool> vb;
typedef vector<char> vc;
#define INF __INT32_MAX__
#define LINF __LONG_LONG_MAX__

int main() {
    int N, M; cin >> N >> M;
    vi S(N), T(N), C(N); rep(i, N) { cin >> S[i] >> T[i] >> C[i]; }

    const int N_MAX = 100005;

    // 種類ごとに店にいた時刻を計測する
    // 各種類で求めた後に、全体で計算する

    vi mm(N_MAX);

    vi imos(N_MAX);
    for (int i = 1; i <= M; i++) {
        // 種類ごとに店にいた時刻を計測
        for (int j = 0; j < N_MAX; j++) imos[j] = 0;


        for (int j = 0; j < N; j++) {
            if (C[j] == i) {
                imos[S[j]]++;
                imos[T[j]]--;
            }
        }

        for (int j = 0; j < N_MAX - 1; j++) {
            imos[j + 1] += imos[j];
        }

        for (int j = 0; j < N_MAX - 1; j++) {
            if (imos[j] == 0 && imos[j + 1] == 1) {
                mm[j]++;
            } else if (imos[j] == 1) mm[j]++;
        }
    }
    int cnt = 0;
    rep(i, N_MAX) {
        cnt = max(cnt, mm[i]);
    }

    cout << cnt << endl;
}