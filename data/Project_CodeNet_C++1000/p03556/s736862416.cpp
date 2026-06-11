#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <iomanip>
#include <math.h>
#include <map>
using namespace std;

int main() {
    long long n;
    cin >> n;
    if (n == 1) cout << 1 << endl;
    for (long long i = 1; i < n; i++) {
        if ((i + 1) * (i + 1) > n) {
            cout << i * i << endl;
            return 0;
        }
    }
}