#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;
    int A, B, C, D, E, F, G, H, Y;
    int a, b, c, d, e, f, g, h, y;
    A = N / 100000000;
    a = N % 100000000;
    B = a / 10000000;
    b = a % 10000000;
    C = b / 1000000;
    c = b % 1000000;
    D = c / 100000;
    d = c % 100000;
    E = d / 10000;
    e = d % 10000;
    F = e / 1000;
    f = e % 1000;
    G = f / 100;
    g = f % 100;
    H = g / 10;
    h = g % 10;
    Y = h / 1;
    y = h / 1;

    if (N % (A + B + C + D + E + F + G + H + Y) == 0) {
        cout << "Yes" << endl;
    }
    else {
        cout << "No" << endl;
    }
    
    return 0;
}