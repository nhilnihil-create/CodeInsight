#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
using namespace std;
int main() {
    int N, H, W, cnt = 0; cin >> N >> H >> W;
    for (int i = 0; i < N; ++i) {
        int a, b; cin >> a >> b;
        if (a >= H && b >= W) cnt++;
    }
    printf("%d\n", cnt);
}
