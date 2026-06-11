#include <iostream>
using namespace std;
int main(void) {
    int A,B,T;
    cin >> A >> B >> T;
    if (T%A==0) {
        cout << (T/A)*B << endl;
    }
    else {
        cout << (T/A)*B;
    }
}
