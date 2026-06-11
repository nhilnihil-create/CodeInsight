#include <bits/stdc++.h>
using namespace std;

int k[20];
int s[20][20];
int p[20];

int main() {
    int N, M;
    cin >> N >> M;
    for (int i = 0; i < M; i++) {
        cin >> k[i];
        for (int j = 0; j < k[i]; j++) {
            cin >> s[i][j];
            s[i][j]--;
        }
    }
    for (int i = 0; i < M; i++) cin >> p[i];

    int ans = 0;
    for (int bit = 0; bit < (1 << N); bit++) {
        bool ok = true;
        for (int i = 0; i < M; i++) {
            int cnt = 0;
            for (int j = 0; j < k[i]; j++) {
                if (bit & (1 << s[i][j])) cnt++;
            }
            if (cnt % 2 != p[i]) {
                ok = false;
                break;
            }
        }
        if (ok) ans++;
    }

    cout << ans << endl;
}