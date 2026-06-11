#include <iostream>
using namespace std;

int main() {
    long long A, B, C;
    cin >> A >> B >> C;
    if (A + B + 1 >= C) cout << B + C << endl;
    else cout << B + (A + B + 1) << endl;
}