#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;
    int x = N;
    int total = 0;
    while (x) {
        total += x % 10;
        x /= 10;
    }
    if (N % total == 0) {
        cout << "Yes" << endl;
        return 0;
    }
    cout << "No" << endl;
    return 0;
}