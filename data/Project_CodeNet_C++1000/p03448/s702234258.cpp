#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
using namespace std;
int main() {
    int A, B, C, X, cnt = 0; cin >> A >> B >> C >> X;
    for (int i = 0; i * 500 <= X && i <= A; ++i) {
        for (int j = 0; j * 100 + i * 500 <= X && j <= B; ++j) {
            int k = (X - (500 * i + 100 * j)) / 50;
            if (C >= k) cnt++;
        }
    }
    printf("%d\n", cnt);
}
