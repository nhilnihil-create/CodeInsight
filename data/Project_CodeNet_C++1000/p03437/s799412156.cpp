#include <iostream>
using namespace std;
int main() {
    long long int X, Y; cin >> X >> Y;
    if (X == Y) {
        printf("%d\n", -1);
        return 0;
    }
    if (X < Y) {
        printf("%d\n", X);
        return 0;
    }
    if (X % Y == 0) {
        printf("%d\n", -1);
        return 0;
    }
    for (long long int i = X; i <= 10e18; i += X) {
        if (i % Y != 0) {
            printf("%lld\n", i);
            return 0;
        }
    }
    printf("%d\n", -1);
}