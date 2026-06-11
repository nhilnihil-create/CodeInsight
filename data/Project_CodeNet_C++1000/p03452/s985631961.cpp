#include <algorithm>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <limits>
#include <map>
#include <queue>
#include <set>
#include <tuple>
#include <vector>

using namespace std;

#define rep(i, n) for (int64_t i = 0; i < (n); i++)
#define irep(i, n) for (int64_t i = 0; i <= (n); i++)
#define rrep(i, n) for (int64_t i = (n)-1; i >= 0; i--)
#define rirep(i, n) for (int64_t i = n; i >= 0; i--)

class WUFTree {
    vector<int> parent;
    vector<int> height;
    vector<int> diff_weight;

public:
    WUFTree(int size)
    {
        for (int i = 0; i < size; i++) {
            parent.push_back(i);
            height.push_back(0);
            diff_weight.push_back(0);
        }
    }
    int root(int node)
    {
        return shrink(node).first;
    }
    void merge(int n0, int n1, int w)
    {
        int r0 = root(n0), r1 = root(n1);
        int z = w + weight(n0) - weight(n1);
        if (r0 == r1) {
            return;
        }
        if (height[r0] < height[r1]) {
            swap(r0, r1);
            z *= -1;
        }
        if (height[r0] == height[r1])
            height[r0]++;
        parent[r1] = r0;
        diff_weight[r1] = z;
    }
    int diff(int n0, int n1)
    {
        return weight(n1) - weight(n0);
    }

protected:
    pair<int, int> shrink(int node)
    {
        if (parent[node] == node) {
            return make_pair(node, 0);
        }
        pair<int, int> p = shrink(parent[node]);
        parent[node] = p.first;
        diff_weight[node] += p.second;
        return make_pair(parent[node], diff_weight[node]);
    }
    int weight(int node)
    {
        return shrink(node).second;
    }
};

int main()
{
    int n, m;
    cin >> n >> m;
    WUFTree uf(n);
    rep(i, m)
    {
        int l, r;
        int d;
        cin >> l >> r >> d;
        l--;
        r--;

        if (uf.root(l) == uf.root(r) && uf.diff(l, r) != d) {
            cout << "No" << endl;
            return 0;
        } else {
            uf.merge(l, r, d);
        }
    }

    cout << "Yes" << endl;
    return 0;
}