#include <iostream>
using namespace std;

int main() {
    int a , b , x;
    cin >> a >> b >> x;

    if ( a > x ) cout << "NO";
    else if ( a == x ) cout << "YES";
    else if ( a < x && a + b >= x ) cout << "YES";
    else if ( a < x && a + b <  x ) cout << "NO";
    return 0;
}