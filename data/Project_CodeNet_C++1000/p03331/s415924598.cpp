#include <iostream>
using namespace std;

int main() {
    int N; cin >> N;
    int ans = 1000000;
    for (int i = 1; i < N; i++) {
        int a = i, b = N - i;
        int dig_sum = 0;
        while (a) {
            dig_sum += a % 10;
            a /= 10;
        }
        while (b) {
            dig_sum += b % 10;
            b /= 10;
        }
        ans = min(ans, dig_sum);
    }
    cout << ans << endl;
}