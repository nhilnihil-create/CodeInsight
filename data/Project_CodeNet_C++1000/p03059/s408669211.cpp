#include <iostream>
using namespace std;
int main() {
    int A, B, T; cin >> A >> B >> T;
    int ans = 0;
    for (int i = A; i <= T; i += A) ans += B;
    printf("%d\n", ans);
}