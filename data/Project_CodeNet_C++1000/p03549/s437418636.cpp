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
    int n, m;
    cin >> n >> m;
    cout << ((n - m) * 100 + 1900 * m) * (1 << m) << endl;
}
