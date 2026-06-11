#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <math.h>
#include <iomanip>
#include <map>
using namespace std;

int main() {
    int a, b, c, d;
    cin >> a >> b >> c;
    int ans = 0;
    d = max(a, max(b, c));
    if (d == a) {
        ans = a * 10 + b + c;
    }
    else if (d == b) {
        ans = b * 10 + a + c;
    }
    else {
        ans = c * 10 + a + b;
    }
    cout << ans << endl;
}