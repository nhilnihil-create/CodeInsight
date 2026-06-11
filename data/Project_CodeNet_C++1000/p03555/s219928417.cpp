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
    vector<char> v(6);
    for (int i = 0; i < 6; i++) {
        cin >> v[i];
    }
    for (int i = 0; i < 3; i++) {
        if (v[i] != v[5 - i]) {
            cout << "NO" << endl;
            return 0;
        }
    }
    cout << "YES" << endl;
}


