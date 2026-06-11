#include <bits/stdc++.h>
using namespace std;

int main() {
    int a, b;
    cin >> a >> b;
    int x = (a + b) / 2 + (((a + b) % 2 == 0) ? 0 : 1);
    cout << x << endl;
}