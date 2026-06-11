#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>

template <class T>
inline void read(T &x) {
    x = 0;
    int f = 0;
    char ch = getchar();
    while (!isdigit(ch))    { f |= ch == '-'; ch = getchar(); }
    while (isdigit(ch))     { x = (x << 1) + (x << 3) + (ch ^ 48); ch = getchar(); }
    x = f ? -x : x;
    return;
}

int c[20][20];
int h, w, ans, a;

int main() {
    read(h), read(w);
    for (int i = 0; i <= 9; ++i)
        for (int j = 0; j <= 9; ++j)
            read(c[i][j]);
    for (int k = 0; k <= 9; ++k)
        for (int i = 0; i <= 9; ++i)
            for (int j = 0; j <= 9; ++j)
                c[i][j] = std::min(c[i][j], c[i][k] + c[k][j]);
    for (int i = 1; i <= h; ++i)
        for (int j = 1; j <= w; ++j)
            read(a), ans += a == -1 ? 0 : c[a][1];
    printf("%d\n", ans);
    return 0;
}