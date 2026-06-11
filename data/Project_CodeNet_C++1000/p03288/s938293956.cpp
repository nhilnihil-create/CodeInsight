#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <iomanip>
#include <numeric>
#include <queue>
#include <cmath>
using namespace std;


int main() {
    int r;
    cin >> r;
    if (r >= 2800) {
        cout << "AGC" << endl;
    } else if (r >= 1200) {
        cout << "ARC" << endl;
    } else {
        cout << "ABC" << endl;
    }
}
