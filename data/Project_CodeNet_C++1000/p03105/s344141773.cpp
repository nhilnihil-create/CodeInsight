#include <iostream>
#define ll long long
using namespace std;

int main() {
    ll a, b, c, d;
    cin >> a >> b >> c;
    b /= a;
    if(b > c) cout << c << endl;
    else cout << b << endl;
    return 0;
}