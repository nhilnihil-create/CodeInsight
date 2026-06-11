#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <math.h>
#include <iomanip>
#include <map>
using namespace std;

int main() {
    vector<char> a(3);
    vector<char> b(3);
    for (int i = 0; i < 3; i++) {
        cin >> a.at(i);
    }
    for (int i = 0; i < 3; i++) {
        cin >> b.at(i);
    }
    if (a.at(0) == b.at(2) && a.at(1) == b.at(1) && a.at(2) == b.at(0)) {
        cout << "YES" << endl;
    }
    else cout << "NO" << endl;
}