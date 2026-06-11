#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll mod = 1000000007;

int main() {
    int H, W;
    int A;
    cin >> H >> W;
    int c[10][10];
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            cin >> c[i][j];
        }
    }

    for (int k = 0; k < 10; k++) {
        for (int i = 0; i < 10; i++) {
            for (int j = 0; j < 10; j++) {
                c[i][j] = min(c[i][j], c[i][k]+c[k][j]);
            }
        }
    }
    
    int ans = 0;
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            cin >> A;
            if (A >= 0) {
                ans += c[A][1];
            }
        }
    }
    cout << ans << endl;
}
