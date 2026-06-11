#include <bits/stdc++.h>
using namespace std;

int main() {
    char X, Y;
    cin >> X >> Y;
    if (X<Y) cout << "<\n";
    else if (X>Y) cout << ">\n";
    else cout << "=\n";
}