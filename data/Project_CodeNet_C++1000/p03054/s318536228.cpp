#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for(int i = 0; i < (n); ++i)

typedef long long ll;
typedef pair<int, int> P;

const int MAX = 1e5 + 5;
const int INF = 1001001001;
const int MOD = 1e9 + 7;

int main(){
    int H, W, N;
    cin >> H >> W >> N;

    int sy, sx;
    cin >> sy >> sx;

    string S, T;
    cin >> S >> T;

    // 駒を取り除ける true 
    bool ans = false;

    char d1[] = {'U', 'D', 'R', 'L'};
    char d2[] = {'D', 'U', 'L', 'R'};
    rep(i, 4) {
        int y = sy - 1, x = sx - 1;
        char c1 = d1[i], c2 = d2[i];
        rep(j, N) {
            if (S[j] == c1) {
                if (c1 == 'U') y--;
                if (c1 == 'D') y++;
                if (c1 == 'R') x++;
                if (c1 == 'L') x--;
            }

            if (x < 0 || W <= x || y < 0 || H <= y) {
                ans = true;
            }

            if (T[j] == c2) {
                if (0 < y && c2 == 'U') y--;
                if (y < H - 1 && c2 == 'D') y++;
                if (x < W - 1 && c2 == 'R') x++;
                if (0 < x && c2 == 'L') x--;
            }
        }
    }

    if (!ans) {
        puts("YES");
    } else {
        puts("NO");
    }
}