#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <math.h>
#include <queue>

using namespace std;
int main() {
    string s;
    cin >> s;
    int a = s[0] - 48, b = s[1] - 48, c = s[2] - 48, d = s[3] - 48;
    if (a + b + c + d == 7)
    {
        cout << a << '+' << b << '+' << c << '+' << d << "=7";
        return 0;
    }
    if (a + b + c - d == 7)
    {
        cout << a << '+' << b << '+' << c << '-' << d << "=7";
        return 0;
    }
    if (a + b - c + d == 7)
    {
        cout << a << '+' << b << '-' << c << '+' << d << "=7";
        return 0;
    }
    if (a + b - c - d == 7)
    {
        cout << a << '+' << b << '-' << c << '-' << d << "=7";
        return 0;
    }
    if (a - b + c + d == 7)
    {
        cout << a << '-' << b << '+' << c << '+' << d << "=7";
        return 0;
    }
    if (a - b + c - d == 7)
    {
        cout << a << '-' << b << '+' << c << '-' << d << "=7";
        return 0;
    }
    if (a - b - c + d == 7)
    {
        cout << a << '-' << b << '-' << c << '+' << d << "=7";
        return 0;
    }
    if (a - b - c - d == 7)
    {
        cout << a << '-' << b << '-' << c << '-' << d << "=7";
        return 0;
    }
}
