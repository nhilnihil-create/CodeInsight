//By Bibi
///                 .-~~~~~~~~~-._       _.-~~~~~~~~~-.
///             __.'              ~.   .~              `.__
///           .'//                  \./                  \`.
///        .'//                     |                     \`.
///       .'// .-~"""""""~~~~-._     |     _,-~~~~"""""""~-. \`.
///     .'//.-"                 `-.  |  .-'                 "-.\`.
///   .'//______.============-..   \ | /   ..-============.______\`.
/// .'______________________________\|/______________________________`.
#include <bits/stdc++.h>
using namespace std;
 
const int N = 1010;
int n, X[N], Y[N];
char s[40];
 
int iabs(int x) { return x > 0 ? x : -x; }
 
int main() {
    scanf("%d", &n);
    int c = 0;
    for (int i = 1; i <= n; i++) {
        scanf("%d%d", &X[i], &Y[i]);
        if ((X[i] + Y[i]) & 1) c++;
        else c--;
    }
    if (iabs(c) != n) {
        puts("-1"); return 0;
    }
    int m = 31 + (c < 0);
    printf("%d\n", m);
    for (int i = 0; i <= 30; i++) printf("%d ", 1 << i);
    if (c < 0) printf("1 ");
    puts("");
    for (int i = 1; i <= n; i++) {
        int x = X[i], y = Y[i], sign = 0;
        if (c < 0) s[31] = 'R', x--;
        for (int j = 30; j >= 0; j--) {
            if (iabs(x) < iabs(y)) swap(x, y), sign ^= 1;
            if (x > 0) x -= 1 << j, s[j] = sign ? 'U' : 'R';
            else x += 1 << j, s[j] = sign ? 'D' : 'L';
        }
        printf("%s\n", s);
    }
    return 0;
}