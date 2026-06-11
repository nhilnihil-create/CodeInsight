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
    long long int a, b, c;
    cin >> a >> b >> c;
    long long int k;
    cin >> k;
    if (k % 2 == 1) {
        cout << b - a << endl;
    } else {
        cout << a - b << endl;
    }
}


