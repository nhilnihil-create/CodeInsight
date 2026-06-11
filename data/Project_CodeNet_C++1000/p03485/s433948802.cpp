#include <iostream>
using namespace std;

int main() {
    int a, b;
    cin >> a >> b;
    if((a+b)/2.0 - (a+b)/2 >= 0.5) {
        cout << (a+b)/2 + 1<< endl;    
    } else {
        cout << (a+b)/2 << endl;
    }
    
}