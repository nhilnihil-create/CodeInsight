#include <iostream>
using namespace std;

int main(void) {
    int a, b;

    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> a >> b;
    cout << ((b % a)? b - a : a + b) << "\n";
    return 0;
}