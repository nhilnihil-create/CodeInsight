#include <iostream>
using namespace std;
int main() {
    int N, H, W; cin >> N >> H >> W;
    int cnt_H = 0, cnt_W = 0;
    for (int i = 1; i <= N; i++) if (i + (H - 1) <= N) cnt_H++;
    for (int i = 1; i <= N; i++) if (i + (W - 1) <= N) cnt_W++;
    printf("%d\n", cnt_H * cnt_W);
}