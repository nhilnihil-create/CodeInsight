#include <bits/stdc++.h>

using namespace std;

int ReturnDigitsSum( int n ) {
    int sum = 0;
    while (n > 0) {
        sum += n % 10;
        n /= 10;
    }

    return sum;
}
int main() {
    int n, a, b;
    cin >> n >> a >> b;;
    int sum_soms = 0;
    for (int i = 1; i < n + 1; i++) {
        int sum = ReturnDigitsSum(i);
        if (sum >= a && sum <= b) sum_soms += i;
    }
    cout << sum_soms << endl;
}