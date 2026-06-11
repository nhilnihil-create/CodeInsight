#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <string>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const int mod = 1000000007;

int main() {
    ios::sync_with_stdio(false);
    int n, k, q, a[2019] = {}, z = mod;
    cin >> n >> k >> q;
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) {
        vector<vector<int>> b;
        vector<int> c;
        b.push_back({});
        for (int j = 0; j < n; j++) {
            if (a[j] >= a[i]) b.back().push_back(a[j]);
            else b.push_back({});
        }
        for (vector<int> j : b) {
            sort(j.begin(), j.end());
            if (j.size() >= k) {
                for (int l = 0; l + k <= j.size(); l++) c.push_back(j[l]);
            }
        }
        sort(c.begin(), c.end());
        if (c.size() >= q) z = min(z, c[q - 1] - c[0]);
    }
    cout << z;
}
