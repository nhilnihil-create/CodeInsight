// 4/26
// Greedy

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main() {
    long long X, Y;
    cin >> X >> Y;

    long long ans = 0;
    long long value = X;

    while (value <= Y) {
        value = value * 2;
        ans++;
        // cout << value << endl;
    }

    cout << ans << endl;
}