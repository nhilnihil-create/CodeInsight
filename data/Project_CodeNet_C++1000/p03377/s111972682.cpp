#include <iostream>
using namespace std;

int main() {

    int a , b , c;
    cin >> a >> b >> c;

    if ( a > c ) cout << "NO";
    else if ( a == c ) cout << "YES";
    else if ( a < c && a + b >= c ) cout << "YES";
    else cout << "NO";
    return 0;
}