#include <bits/stdc++.h>

#define rep(x, y) for (int i = (x); i < (y); i++)

typedef long long ll;

using namespace std;

int main() {
    int a, b;
    cin >> a >> b;

    cout << ((a * b) - (a + b - 1)) << endl;

    return 0;
}