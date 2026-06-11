//2020-08-30, Sun

#include<iostream>
using namespace std;

int sumer(int i) {
    int sum = 0;
    while (i > 0) {
        sum += i % 10;
        i /= 10;
    }
    return sum;
}

int main() {
    int a, b, n, ans = 0;
    cin >> n >> a >> b;
    
    for (int i = 1; i <= n; i++) {
        int sum = sumer(i);
        if (sum >= a && sum <= b) {
            ans += i;
        }
    }

    cout << ans << endl;

    return 0;
}