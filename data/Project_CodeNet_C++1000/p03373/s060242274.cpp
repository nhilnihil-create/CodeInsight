// Half and Half
#include <iostream>
#include <algorithm>
#include <bits/stdc++.h>
using namespace std;

int main() {
    int A, B, C, X, Y;
    cin >> A >> B >> C >> X >> Y;
    int money = 1 << 30;
    for (int i = 0; i <= 100000; i++) {
        money = min(money, i * 2 * C + max(0, X-i) * A + max(0, Y-i) * B);
    }
    cout << money << endl;
}