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
    int n, a, b;
    cin >> n >> a >> b;
    if (abs(a - b) % 2 == 1) {
        cout << "Borys" << endl;
    } else {
        cout << "Alice" << endl;
    }
}




