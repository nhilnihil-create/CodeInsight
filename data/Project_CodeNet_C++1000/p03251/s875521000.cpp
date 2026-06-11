#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <math.h>
#include <iomanip>
#include <map>
using namespace std;

int main() {
    int n, m, x, y;
    cin >> n >> m >> x >> y;
    vector<int> xx(n);
    vector<int> yy(m);
    int maxx = -101;
    int miny = 101;
    for (int i = 0; i < n; i++) {
        cin >> xx.at(i);
        maxx = max(maxx, xx.at(i));
    }
    for (int i = 0; i < m; i++) {
        cin >> yy.at(i);
        miny = min(miny, yy.at(i));
    }
    if (maxx < miny) {
        for (int i = maxx + 1; i <= miny; i++) {
            if(x < i && i <= y) {
                cout << "No War" << endl;
                return 0;
            }
        }
    }
    cout << "War" << endl;
}