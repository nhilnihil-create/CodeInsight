#include <iostream>
#include <map>
#include <algorithm>
#include <vector>
#include <iomanip>
#include <sstream>
#include <cmath>
#include <math.h>
#include <string>
using namespace std;
typedef long long ll;
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    int a, b, c, d;
    a = n / 1000;
    b = n / 100 % 10;
    c = n / 10 % 10;
    d = n % 10;
    if ( a + b + c + d == 7 ) cout << a << '+' << b << '+' << c << '+' << d << "=7";
    else if ( a + b + c - d == 7 ) cout << a << '+' << b << '+' << c << '-' << d << "=7";
    else if  ( a + b - c + d == 7 ) cout << a << '+' << b << '-' << c << '+' << d << "=7";
    else if ( a - b + c + d == 7 ) cout << a << '-' << b << '+' << c << '+' << d << "=7";
    else if ( a + b - c - d == 7 ) cout << a << '+' << b << '-' << c << '-' << d << "=7";
    else if ( a - b - c + d == 7 ) cout << a << '-' << b << '-' << c << '+' << d << "=7";
    else if ( a - b + c - d == 7 ) cout << a << '-' << b << '+' << c << '-' << d << "=7";
    else if ( a - b - c - d == 7 ) cout << a << '-' << b << '-' << c << '-' << d << "=7";
}
