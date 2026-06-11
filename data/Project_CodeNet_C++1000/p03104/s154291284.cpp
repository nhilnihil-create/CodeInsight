#include <iostream>

using namespace std;

int main() {
    long long a, b; cin >> a >> b;
    if (a == 0) {
        b = ((b+1)/2%2) ^ ((b%2)?0:b);
        cout << b << endl;
        return 0;
    }

    a = ((a)/2%2) ^ (((a-1)%2)?0:a-1);
    b = ((b+1)/2%2) ^ ((b%2)?0:b);
    cout << (a ^ b) << endl;
    return 0;
}