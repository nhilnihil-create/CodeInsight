#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    int H, W;
    int ans = 0;
    cin >> H >> W;
    int a[H][W];
    int X[250000][4];
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            cin >> a[i][j];
        }
    }

    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W-1; j++) {
            if (a[i][j] % 2 == 1) {
                a[i][j+1] += 1;
                X[ans][0] = i+1;
                X[ans][1] = j+1;
                X[ans][2] = i+1;
                X[ans][3] = j+2;
                ans++;
            }
        }
    }
    for (int i = 0; i < H-1; i++) {
        if (a[i][W-1] % 2 == 1) {
            a[i+1][W-1] += 1;
            X[ans][0] = i+1;
            X[ans][1] = W;
            X[ans][2] = i+2;
            X[ans][3] = W;
            ans++;
        }
    }

    cout << ans << endl;
    for (int i = 0; i < ans; i++) {
        cout << X[i][0] << " " << X[i][1] << " " << X[i][2] << " " << X[i][3] << endl;
    }
}
