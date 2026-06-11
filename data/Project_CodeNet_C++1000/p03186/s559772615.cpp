#include <iostream>

using namespace std;

int main() {
    long long int A, B, C;
    cin >> A >> B >> C;
    
    if(C>B+1) {
        if(C>A+B+1) {
            cout << B+(A+B+1) << endl;
        } else {
            cout << B+C << endl;
        }
    } else {
        cout << B+C << endl;
    }


    return 0;
    
}