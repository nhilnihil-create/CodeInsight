#include <iostream>
using namespace std;

int main() {
    int n, b;
    cin >> n;
    unsigned long long res = 0;
    for (int i = 0; i < n; ++i) {
        cin >> b;
        res += b - 1;
    }
    cout << res;
}