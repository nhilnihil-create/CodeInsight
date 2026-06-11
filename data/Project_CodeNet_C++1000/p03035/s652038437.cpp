#include <iostream>
using namespace std;

int main() {
    int A;
    cin >> A; // 0 ≤ A ≤ 100
    int B;
    cin >> B; // 2 ≤ A ≤ 1000 , B is even
    if (A >= 13) cout << B;
    else {
        if (A <= 12 && A >= 6) cout << B / 2;
        else
           cout << "0";
    }
    return 0;
}