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
bool f(const vector<int>& v) {
    for (auto num : v) {
        if (num > 1) return false;
    }
    return true;
}

int main() {
    int n;
    cin >> n;
    vector<int> v(n, 0);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    long long int res = 0;
    vector<int> state(20, 0);
    int b = 0, e = 0;
    for (int i = 0; i < 20; i++) {
        state[i] += (v[0] >> i) % 2;
    }
    while (b < n) {
        while (e < n && f(state)) {
            e++;
            for (int i = 0; i < 20; i++) {
                state[i] += (v[e] >> i) % 2;
            }
        }
        res += e - 1 - b + 1;
        // if (f(state)) res++;
        for (int i = 0; i < 20; i++) {
            state[i] -= (v[b] >> i) % 2;
        }
        b++;
    }
    cout << res << endl;
}
