#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
using namespace std;
int main() {
    int a, b, c, d; cin >> a >> b >> c >> d;
    int e = c - (d - b), f = d + (c - a), g = a - (d - b), h = b + (c - a);
    cout << e << " " << f << " " << g << " " << h << endl;
}
