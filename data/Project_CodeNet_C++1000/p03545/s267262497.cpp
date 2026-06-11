#include <iostream>
#include <cmath>
#include <vector>
#include <map>
#include <iomanip>
#include <algorithm>
#include <sstream>
#include <string>
#include <math.h>
#include <set>
#include <deque>
using namespace std;
typedef long long ll;
const int mod = 1000000007;

int main() {
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    int a, b, c, d;
    a = n / 1000;
    b = n / 100 % 10;
    c = n / 10 % 10;
    d = n % 10;
    if (a + b + c + d == 7) cout << a << '+' << b << '+' << c << '+' << d << "=7";
    else if (a + b + c - d == 7) cout << a << '+' << b << '+' << c << '-' << d << "=7";
    else if (a + b - c - d == 7) cout << a << '+' << b << '-' << c << '-' << d << "=7";
    else if (a + b - c + d == 7) cout << a << '+' << b << '-' << c << '+' << d << "=7";
    else if (a - b - c - d == 7) cout << a << '-' << b << '-' << c << '-' << d << "=7";
    else if (a - b - c + d == 7) cout << a << '-' << b << '-' << c << '+' << d << "=7";
    else if (a - b + c + d == 7) cout << a << '-' << b << '+' << c << '+' << d << "=7";
    else if (a - b + c - d == 7) cout << a << '-' << b << '+' << c << '-' << d << "=7";
    
}