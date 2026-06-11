#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    int a, b, c;
    cin >> a >> b >> c;

    cout << max({10*a+b+c, 10*b+a+c, 10*c+a+b}) << endl;

    return 0;
}