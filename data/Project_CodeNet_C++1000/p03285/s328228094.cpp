#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
using namespace std;
int main() {
    int N; cin >> N;
    for (int i = 0; i <= 30; i++) {
        for (int j = 0; j <= 30; j++) {
            if (i * 4 + j * 7 == N) {
                printf("%s\n", "Yes");
                return 0;
            }
        }
    }
    printf("%s\n", "No");
    return 0;
}
