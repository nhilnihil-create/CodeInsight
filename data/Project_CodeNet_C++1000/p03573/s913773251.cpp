#include <iostream>
using namespace std;
int main() {
    int a, b, c;
    cin >> a >> b >> c;
    if (a == b && c != a && c != b) {
        cout << c;
    } else if (a == c && b != a){
        cout << b;
    } else{
        cout<<a;
    }

}