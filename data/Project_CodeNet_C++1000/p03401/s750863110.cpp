#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <math.h>
#include <iomanip>
#include <map>
using namespace std;

int main() {
    int n;
    cin >> n;
    int all = 0;
    vector<int> a(n);
    vector<int> dif(n + 1);
    for (int i = 0; i < n; i++) {
        cin >> a.at(i);
    }
    dif.at(0) = abs(a.at(0));
    dif.at(n) = abs(a.at(n - 1));
    for (int i = 1; i < n; i++) {
        dif.at(i) = abs(a.at(i) - a.at(i - 1));
    }
    for (int i = 0; i < n + 1; i++) {
        all += dif.at(i);
    }
    int first = all;
    first -= (dif.at(0) + dif.at(1));
    first += abs(a.at(1));
    cout << first << endl;
    for (int i = 1; i < n - 1; i++) {
        int ans = all;
        ans -= (dif.at(i) + dif.at(i + 1));
        ans += abs(a.at(i + 1) - a.at(i - 1));
        cout << ans << endl;
    }
    int last = all;
    last -= (dif.at(n) + dif.at(n - 1));
    last += abs(a.at(n - 2));
    cout << last << endl;
}