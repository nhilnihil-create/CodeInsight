#include <bits/stdc++.h>
using namespace std;
#define rep(i, c) for (int i = 0; i < (int)c; i++)
int main() {
    int n;
    scanf("%d", &n);
    int t = 0, x = 0, y = 0;
    rep(i, n) {
        int next_t, next_x, next_y;
        scanf("%d%d%d", &next_t, &next_x, &next_y);
        int distance = abs(x - next_x) + abs(y - next_y);
        int timeleft = next_t - t;

        // 次の地点にたどり着けない
        if(distance > timeleft) {
            printf("No\n");
            return 0;
        }

        // 次の地点を越えれるけど偶奇が一致しないので、行って帰っての時間消費ができない
        if((timeleft % 2) != (distance % 2)) {
            printf("No\n");
            return 0;
        }

        t = next_t, x = next_x, y = next_y;
    }
    printf("Yes\n");
    return 0;
}