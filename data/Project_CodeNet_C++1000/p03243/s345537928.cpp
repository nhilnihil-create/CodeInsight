#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
using namespace std;
int main() {
    int N; cin >> N;
    for (int i = N; i <= 999; i++) {
        int num = i;
        int a = num / 100;
        num = num % 100;
        int b = num / 10;
        num = num % 10;
        if (a == b && b == num) {
            printf("%d\n", i);
            return 0;
        }
    }
    return 0;
}
