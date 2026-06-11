#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    int ones = n % 10;
    n /= 10;
    int tens = n % 10;
    n/= 10;
    int hundreds = n % 10;

    if (ones > tens) {
        tens++;
    }
    if (tens <= hundreds) {
        cout << hundreds << hundreds << hundreds << endl;
    } else {
        hundreds++;
        cout << hundreds << hundreds << hundreds << endl;
    }
}
