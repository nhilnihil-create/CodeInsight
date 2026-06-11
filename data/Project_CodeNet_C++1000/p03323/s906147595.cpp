#include <iostream>
using namespace std;
int main () {
    int a, b;
    cin >> a >> b;
    if (a<=8 && a>=1 && b<=8 && b>=1) cout << "Yay!";
    else cout << ":(";
    return 0;
}