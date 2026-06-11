#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
using namespace std;
int main() {
    int N, M, C; cin >> N >> M >> C;
    vector<int> B(M, 0);
    int cnt = 0;
    for (int i = 0; i < M; ++i) cin >> B[i];
    for (int i = 0; i < N; ++i) {
        int sum = 0;
        for (int j = 0; j < M; ++j) {
            int a; cin >> a;
            sum += a * B[j];
        }
        if (sum + C > 0) cnt++;
    }
    printf("%d\n", cnt);
}
