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
    int n;
    cin >> n;
    vector<int> v(n + 2, 0);
    for (int i = 1; i <= n; i++) {
        cin >> v[i];
    }
    int s = 0;
    for (int i = 1; i < v.size(); i++) {
        s += abs(v[i] - v[i - 1]);
    }
    for (int i = 1; i < v.size() - 1; i++) {
        cout << s - abs(v[i] - v[i - 1]) - abs(v[i + 1] - v[i]) + abs(v[i + 1] - v[i - 1]) << endl;
    }
}
