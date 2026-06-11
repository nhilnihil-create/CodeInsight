#include <iostream>
using namespace std;
int main() {
    int A, B, C;
    while(cin >> A >> B >> C) {
        if (B / A >= C) {
            cout << C << endl;
        } else {
            cout << B / A << endl;
        }
    }
    return 0;
}
