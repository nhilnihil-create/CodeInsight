#include <bits/stdc++.h>
using namespace std;
 
int main() {
    double a, b, x;
    cin >> a >> b;
    x = (a + b) / 2;
    if (x > (int)x) x = int (x += 1);
    cout << x << endl;
}
