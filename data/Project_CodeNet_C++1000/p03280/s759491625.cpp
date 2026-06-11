#include <iostream>
using namespace std;
void func() {
    int A,B;
    cin >> A >> B;
    cout << A * B - (A + B - 1) << endl;
}

int main() {
    func();
    return 0;
}