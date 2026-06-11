#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0) , cin.tie(0) , cout.tie(0);

    int a , b;
    cin >> a >> b;

    if (a >= 13)
        cout << b;
    else if (a >= 6 && a <= 12)
        cout << b / 2;
    else
        cout << 0;
}
