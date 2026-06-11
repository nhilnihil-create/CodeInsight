#include <iostream>
using namespace std;
int main() {
    int N; cin >> N;
    for (int i = max(2, N); i <= 10e9; i += max(2, N)) {
        if (i % N == 0 && i % 2 == 0) {
            printf("%d\n", i); break;
        }
    }
}