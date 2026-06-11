#include <iostream>
using namespace std;

int calc_sum(int n) {
    int sum = 0;
    while (n > 0) {
        sum += n % 10;
        n /= 10;
    }
    return sum;
}

int main() {
    int n;
    cin >> n;
    int a, b;
    cin >> a >> b;
    int res = 0;
    for (int i = 1; i <= n; i++) {
        int sum = calc_sum(i);
        if (sum >= a && sum <= b) {
            res += i;
        }
    }
    cout << res << endl;
    return 0;
}
