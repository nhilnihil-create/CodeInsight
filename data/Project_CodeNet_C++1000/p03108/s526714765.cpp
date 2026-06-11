#include <vector>
#include <stack>
#include <queue>
#include <list>
#include <bitset>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>
#include <numeric>
#include <iostream>
#include <iomanip>
#include <string>
#include <chrono>
#include <random>
#include <cmath>
#include <cassert>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <functional>
#include <sstream>

using namespace std;

class DisjointSet {
    public:
        DisjointSet(int n) : N(n), pars(n, -1), sz(n) {

        }


        int find(int x) {
            return pars[x] < 0 ? x : (pars[x] = find(pars[x]));
        }

        bool unite(int x, int y) {
            x = find(x), y = find(y);
            if (x == y) {
                return false;
            }
            --sz;
            if (pars[x] < pars[y]) {
                swap(x, y);
            }
            pars[y] += pars[x];
            pars[x] = y;
            return true;
        }

        int size() { return sz; }
        int count(int x) {
             return -pars[find(x)];
        }

    private:
        int N;
        int sz;
        vector<int> pars;
};


int main(int argc, char** argv) {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;
    vector<pair<int,int>> edges;
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        --u, --v;
        edges.emplace_back(u, v);
    }

    DisjointSet ds(n);
    vector<long long> res(m, 0);

    for (int i = m - 1; i >= 0; --i) {
        int u = edges[i].first, v = edges[i].second;

        u = ds.find(u), v = ds.find(v);
        if (u != v) {
            res[i] = ds.count(u) * 1LL * ds.count(v);
            ds.unite(u, v);
        }
    }
    for (int i = 1; i < m; ++i) {
        res[i] += res[i - 1];
    }

    for (int i = 0; i < m; ++i) {
        cout << res[i] << '\n';
    }
    return 0;
}