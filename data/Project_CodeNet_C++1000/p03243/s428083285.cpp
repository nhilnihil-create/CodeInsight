#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;
    n = (n - 1)/111 + 1;
    cout << 111*n;
}