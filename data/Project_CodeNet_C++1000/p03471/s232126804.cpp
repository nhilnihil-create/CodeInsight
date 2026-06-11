#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
typedef long long ll;
typedef vector<vector<int>> vv;
typedef pair<int, int> P;

// input
int N, Y;


void input() {
    cin >> N >> Y;
}


int main() {
    input();
    rep(x, N + 1) rep(y, N + 1) {
        int s = Y - (10000 * x + 5000 * y);
        if (s < 0) continue;
        int z = s / 1000;
        if (x + y + z == N) {
            printf("%d %d %d\n", x, y, z);
            return 0;
        }
    }
    printf("%d %d %d\n", -1, -1, -1);
}
