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

int f(unordered_map<int, unordered_set<int>>& um) {
    unordered_set<int> us;
    int c = 0;
    for (auto p : um) {
        int now = p.first;
        if (us.find(now) == us.end()) {
            c++;
            us.insert(now);
            vector<int> v(1, now);
            while(v.size() > 0) {
                int index = v.back();
                v.pop_back();
                for (auto next : um[index]) {
                    if (us.find(next) == us.end()) {
                        us.insert(next);
                        v.push_back(next);
                    }
                }
            }
        }
    }
    return c;
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<pair<int, int>> vp;
    unordered_map<int, unordered_set<int>> um;
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        vp.emplace_back(a, b);
        um[a].insert(b);
        um[b].insert(a);
    }
    int res = 0;
    for (auto p : vp) {
        int a = p.first, b = p.second;
        um[a].erase(b);
        um[b].erase(a);
        if (f(um) > 1) res++;
        um[a].insert(b);
        um[b].insert(a);
    }
    cout << res << endl;
}


