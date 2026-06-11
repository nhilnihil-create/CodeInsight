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
    vector<int> v(n, 0);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    vector<long long int> res(n, 0);
    vector<int> next(n, -1);
    unordered_map<int, int> um;
    for (int i = n - 1; i >= 0; i--) {
        if (um.find(v[i]) != um.end()) {
            next[i] = um[v[i]];
        }
        um[v[i]] = i;
    }
    res[0] = 1;
    const int mod = 1e9 + 7;
    long long int c = 0;
    for (int i = 0; i < n; i++) {
        c += res[i];
        c %= mod;
        if (next[i] != -1 && next[i] - i > 1) {
            res[next[i]] += c;
            res[next[i]] %= mod;
        }
    }
    cout << c << endl;
}


