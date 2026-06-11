#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
using namespace std;
int main() {
    int N; cin >> N;
    int ans = 0;
    for (int i = 0; i < N; ++i) {
        int a; cin >> a;
        if (a % 2 == 0) ans++;
    }
    double sum = pow(3, N) - pow(2, ans);
    printf("%d\n", (int)sum);
}
