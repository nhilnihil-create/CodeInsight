#include<bits/stdc++.h>
using namespace std;

const int MN = 200010;

int H, W, N;
set<int> st[MN];

int main() {
    scanf("%d %d %d", &H, &W, &N);

    for(int i = 0; i < N; i++) {
        int x, y; scanf("%d %d", &x, &y);
        x--; y--;

        st[y].insert(x);
    }
    for(int i = 0; i < W; i++) st[i].insert(H);

    int x = 0, y = 0, t = 1, ans = *st[0].upper_bound(0);
    while(1) {
        if(t) {
            int t = *st[y].upper_bound(x);
            if(x + 1 == t) break;
            x++;
        }
        else {
            if(y < W - 1) {
                int t = *st[y + 1].lower_bound(x);
                if(t != x) {
                    y++;
                    ans = min(ans, *st[y].upper_bound(x));
                }
            }
        }
        t ^= 1;
    }
    printf("%d", ans);
}
