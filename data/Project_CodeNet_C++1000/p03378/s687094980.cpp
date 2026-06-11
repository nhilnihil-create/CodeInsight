#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
using namespace std;
int main() {
    int N, M, X; cin >> N >> M >> X;
    int cnt_z = 0, cnt_n = 0;
    for (int i = 0; i < M; ++i) {
        int a; cin >> a;
        if (0 <= a && a <= X) cnt_z++;
        if (X <= a && a <= N) cnt_n++;
    }
    printf("%d\n", min(cnt_z, cnt_n));
}
