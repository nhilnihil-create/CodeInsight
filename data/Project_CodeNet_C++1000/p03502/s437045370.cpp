#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    int hold = n, sum = 0;
    while (hold) {
        sum += hold % 10;
        hold /= 10;
    }
    if (n % sum == 0) {
        cout << "Yes";
    } else {
        cout << "No";
    }
    return 0;
}