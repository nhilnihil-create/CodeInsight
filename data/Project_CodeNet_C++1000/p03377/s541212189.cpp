#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <math.h>
#include <iomanip>
#include <map>
using namespace std;

int main() {
    int a, b, x;
    cin >> a >> b >> x;
    if (x - a > b || x - a < 0) {
        cout << "NO" << endl;
    }
    else cout << "YES" << endl;
}