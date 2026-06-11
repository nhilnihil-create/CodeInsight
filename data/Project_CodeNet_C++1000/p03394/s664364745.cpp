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
    if (n == 3) {
        cout << "2 5 63" << endl;
        return 0;
    }
    vector<vector<int>> v(6, vector<int>(0));
    for (int i = 30000; i >= 2; i--) {
        if (i % 2 == 0 || i % 3 == 0) {
            v[i % 6].push_back(i);
        }
    }
    vector<int> res;
    res.push_back(v[2].back());
    v[2].pop_back();
    res.push_back(v[3].back());
    v[3].pop_back();
    res.push_back(v[3].back());
    v[3].pop_back();
    res.push_back(v[4].back());
    v[4].pop_back();
    
    n -= 4;
    if (n % 2 == 1) {
        res.push_back(v[0].back());
        v[0].pop_back();
        n--;
    }
    while (n > 0) {
        if (v[0].size() >= 2) {
            res.push_back(v[0].back());
            v[0].pop_back(); 
            res.push_back(v[0].back());
            v[0].pop_back();
        } else if (v[3].size() >= 2) {
            res.push_back(v[3].back());
            v[3].pop_back(); 
            res.push_back(v[3].back());
            v[3].pop_back();
        } else {
            res.push_back(v[2].back());
            v[2].pop_back();
            res.push_back(v[4].back());
            v[4].pop_back();
        }
        n -= 2;
    }
    for (auto num : res) {
        cout << num << " ";
    }
    cout << endl;
}
