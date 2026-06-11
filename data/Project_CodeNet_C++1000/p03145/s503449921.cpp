#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <iomanip>
#include <math.h>
#include <map>
using namespace std;

int main() {
    int a, b, c;
    cin >> a >> b >> c;
    int maxi = max(a, max(b, c));
    int ans;
    if (maxi == a) {
        ans = b * c / 2;
    }
    else if (maxi == b) {
        ans = a * c / 2;
    }
    else ans = b * a / 2;
    cout << ans << endl;
}
