#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <cmath>
#include <climits>
#include <algorithm>
#include <utility>
 
using namespace std;
using Int = long long int;
using UInt = unsigned long long int;
using VI = vector<long long int>;

int main(void) {
    Int n, m;
    cin >> n >> m;
    vector<pair<Int, Int> > v(n);
    for (Int i = 0; i < n; ++i) {
        cin >> v[i].first >> v[i].second;
    }
    sort(v.begin(), v.end());

    Int cost = 0;
    Int drinkNum = m;
    for (Int i = 0; i < n; i++) {
        if (v[i].second <= drinkNum) {
            cost += (v[i].first * v[i].second);
            drinkNum -= v[i].second;
        } else {
            cost += (v[i].first * drinkNum);
            drinkNum = 0;
            break;
        }
    }
    cout << cost << endl;
    return 0;
}

