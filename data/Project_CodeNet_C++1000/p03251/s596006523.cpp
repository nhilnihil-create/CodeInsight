#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
using namespace std;
int main() {
    int N, M, X, Y; cin >> N >> M >> X >> Y;
    int x_num = 0, y_num = 10e5;
    for (int i = 0; i < N; i++) {
        int tmp; cin >> tmp;
        if (i == 0) x_num = tmp;
        else x_num = max(x_num, tmp);
    }
    for (int i = 0; i < M; i++) {
        int tmp; cin >> tmp;
        if (i == 0) y_num = tmp;
        else y_num = min(y_num, tmp);
    }
    for (int i = X + 1; i <= Y; i++) {
        if (i <= y_num && i > x_num) {
            printf("%s\n", "No War");
            return 0;
        }
    }
    printf("%s\n", "War");
    return 0;
}