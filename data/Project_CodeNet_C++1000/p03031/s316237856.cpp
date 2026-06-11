#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;

int main() {
    int N, M;
    cin >> N >> M;
    int k[M], s[M][N], p[M];
    for (int i = 0; i < M; i++) {
        cin >> k[i];
        for (int j = 0; j < k[i]; j++) {
            cin >> s[i][j];
        }
    }
    for (int i = 0; i < M; i++) {
        cin >> p[i];
    }
    int ans = 0;
    for (int bit = 0; bit < (1 << N); ++bit) {
        bool switch_on[N];
        for (int i = 0; i < N; ++i) {
            if (bit & (1 << i)) {
                switch_on[i] = true;
            } else {
                switch_on[i] = false;
            }
        }

        bool is_all_lights_on = true;
        for (int i = 0; i < M; i++) {
            int total = 0;
            for (int j = 0; j < k[i]; j++) {
                if (switch_on[s[i][j] - 1]) {
                    total++;
                }
            }
            if (total % 2 != p[i]) {
                is_all_lights_on = false;
            }
        }
        if (is_all_lights_on) ans++;
    }
    cout << ans << endl;
    return 0;
}