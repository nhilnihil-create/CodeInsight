#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    int a, b;
    cin >> a >> b;

    if (b%a == 0) cout << a+b << endl;
    else cout << b-a << endl;

    return 0;
}