#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
using namespace std;
int main() {
    int N, mini = 10e9 + 1, maxi = 0; cin >> N;
    for (int i = 0; i < N; i++) {
        int a; cin >> a;
        mini = min(mini, a), maxi = max(maxi, a);
    }
    printf("%d\n", maxi - mini);
}
