#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <iomanip>
#include <math.h>
#include <map>
using namespace std;

int main() {
    int h, w, a, b;
    cin >> h >> w >> a >> b;
    int ans = h * w;
    ans -= a * w;
    ans -= b * h;
    ans += a * b;
    cout << ans << endl;
}