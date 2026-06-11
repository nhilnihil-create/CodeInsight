#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
using namespace std;
int main() {
    int N, D, X; cin >> N >> D >> X;
    int cnt = 0;
    for (int i = 0; i < N; ++i) {
        int a; cin >> a;
        for (int j = 1; j <= D; j += a) cnt++;
    }
    printf("%d\n", cnt + X);
}
