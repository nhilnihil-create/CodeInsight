#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;

const int MAX_N = 1e4, M = 30;

struct Point {
    int x, y;
};

int N;
Point poi[MAX_N];
char seq[MAX_N];

int main() {
    scanf("%d", &N);
    bool odd = false, even = false;
    for (int i = 1; i <= N; i++) {
        scanf("%d%d", &poi[i].x, &poi[i].y);
        if (poi[i].x + poi[i].y & 1) odd = true;
        else even = true;
    }
    if (odd && even) {
        printf("-1\n");
        return 0;
    }
    if (even) {
        seq[M + 1] = 'U';
        for (int i = 1; i <= N; i++) poi[i].y--;
    }
    printf("%d\n", M + 1 + even);
    for (int i = 0; i <= M; i++) printf("%d ", 1 << i);
    if (even) printf("%d ", 1);
    printf("\n");
    for (int i = 1; i <= N; i++) {
        Point p = poi[i];
        for (int j = M; j >= 0; j--) {
            int v = 1 << j;
            if (abs(p.x) > abs(p.y)) {
                if (p.x > 0) seq[j] = 'R', p.x -= v;
                else seq[j] = 'L', p.x += v;
            } else {
                if (p.y > 0) seq[j] = 'U', p.y -= v;
                else seq[j] = 'D', p.y += v;
            }
        }
        printf("%s\n", seq);
    }
}
