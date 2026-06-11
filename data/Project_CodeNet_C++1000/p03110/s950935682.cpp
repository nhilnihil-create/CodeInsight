#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <iomanip>
#include <math.h>
#include <map>
using namespace std;

int main() {
    int n;
    double sum = 0;
    cin >> n;
    vector<pair<double, string>> a(n);
    for (int i = 0; i < n; i++) {
        double aa;
        string b;
        cin >> aa >> b;
        a.at(i) = make_pair(aa, b);
    }
    for (int i = 0; i < n; i++) {
        if (a.at(i).second == "JPY") {
            sum += a.at(i).first;
        }
        else sum += a.at(i).first * 380000;
    }
    cout << fixed << setprecision(10) << sum << endl;
}