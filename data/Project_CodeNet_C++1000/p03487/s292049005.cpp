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
    unordered_map<int, int> um;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        um[a]++;
    }
    int res = 0;
    for (auto p : um) {
        if (p.first <= p.second) {
            res += p.second - p.first;
        } else {
            res += p.second;
        }
    }
    cout << res << endl;
}


