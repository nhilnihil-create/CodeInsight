#include <math.h>

#include <bitset>
#include <cmath>
#include <iostream>
using namespace std;
int main() {
    int l, c = 0;
    string a;
    cin >> a;
    l = a.size();
    for (int i = 0; i < l; i++) {
        char d = a[i];
        if (i % 2 == 0) {
            if (d == '0') c++;
        } else if (d == '1')
            c++;
    }
    cout << min(c, l - c) << endl;
    return 0;
}