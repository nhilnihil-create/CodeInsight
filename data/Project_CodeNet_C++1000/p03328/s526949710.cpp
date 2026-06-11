#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <math.h>
#include <iomanip>
#include <map>
using namespace std;

int main() {
    int a, b;
    cin >> a >> b;
    vector<int> r(999);
    r.at(0) = 1;
    for (int i = 1; i < 999; i++) {
        r.at(i) += r.at(i - 1) + i + 1;
    }
    int dif = b - a;
    int ans = r.at(dif - 2) - a;
    cout << ans << endl;
}