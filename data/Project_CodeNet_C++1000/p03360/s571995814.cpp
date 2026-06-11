#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <algorithm>
#include <math.h>
#include <map>
using namespace std;

int main() {
    int a, b, c, k;
    cin >> a >> b >> c >> k;
    int maxi = max(a, max(b, c));
    for (int i = 0; i < k; i++) {
        maxi *= 2;
    }
    cout << a + b + c + maxi - max(a, max(b, c)) << endl;
}