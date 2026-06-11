#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;
#define rep(i,n) for(int i = 0; i < ((int)(n)); i++)   // 0-indexed昇順

int main() {
    ll R, G, B, N; cin >> R >> G >> B >> N;
    ll res = 0;
    for (int i = 0; i <= N / R; i++) {
        for (int j = 0; j <= N / G; j++) {
            int left = N - i * R - j * G;
            if (left >= 0 && left % B == 0) {
//                printf("%d %d %d\n", i, j, left / B);
                res++;
            }
        }
    }
    cout << res << endl;
}
