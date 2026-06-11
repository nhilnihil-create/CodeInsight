#include <iostream>
#include <vector>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <iomanip>
#include <numeric>
#include <queue>
#include <cmath>
using namespace std;

int g(int a, vector<int> va) {
    unordered_map<int, int> um1, um2;
    for (auto node : va) {
        um2 = um1;
        for (auto p : um1) {
            if (um2.find(p.first + node) == um2.end() || p.second + 10 < um2[p.first + node]) {
                um2[p.first + node] = p.second + 10;
            }
        }
        um1 = um2;
        um1[node] = 0;
    }
    int res = -1;
    for (auto p : um1) {
        int r = p.second + abs(p.first - a);
        if (res == -1 || r < res) {
            res = r;
        }
    }
    return res;
}

void f(int index, const vector<int>& v, int a, int b, int c, vector<int> va, vector<int> vb, vector<int> vc, int& res) {
    if (index == v.size()) {
        if (va.empty() || vb.empty() || vc.empty()) return;
        int cost = 0;
        cost += g(a, va);
        cost += g(b, vb);
        cost += g(c, vc);
        if (res == -1 || cost < res) res = cost;
        return;
    }

    va.push_back(v[index]);
    f(index + 1, v, a, b, c, va, vb, vc, res);
    va.pop_back();
    vb.push_back(v[index]);
    f(index + 1, v, a, b, c, va, vb, vc, res);
    vb.pop_back();
    vc.push_back(v[index]);
    f(index + 1, v, a, b, c, va, vb, vc, res);
    vc.pop_back();
}

int main() {
    int n, a, b, c;
    cin >> n >> a >> b >> c;
    vector<int> v;
    for (int i = 0; i < n; i++) {
        int t;
        cin >> t;
        v.push_back(t);
    }

    vector<int> va, vb, vc;
    int res = -1;
    f(0, v, a, b, c, va, vb, vc, res);
    cout << res << endl;
}
