// Move and Win
#include <cmath>
#include <iostream>
#include <algorithm>
#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, A, B;
    cin >> N >> A >> B;
    bool win = false;
    if ((B - A) % 2 == 0) win = true;
    if (win) cout << "Alice" << endl;
    else cout << "Borys" << endl;
}