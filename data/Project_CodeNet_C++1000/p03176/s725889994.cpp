#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

const int N = 2e5 + 2;

struct Fenwick {
    int n;
    long long node[N];
    void update(int u, long long val)
    {
        for (; u <= n; u += u & -u)
            node[u] = max(node[u], val);
    }
    long long query(int u)
    {
        long long max_pref = 0;
        for (; u > 0; u -= u & -u)
            max_pref = max(max_pref, node[u]);
        return max_pref;
    }
    void set_n(int _n)
    {
        n = _n;
    }
} tree;

int main()
{
    int n;
    cin >> n;
    vector<int> h(n), a(n);
    for (int& x : h)
        cin >> x;
    for (int& x : a)
        cin >> x;

    tree.set_n(n);

    long long res = 0;
    for (int i = 0; i < n; ++i) {
        long long max_pref = tree.query(h[i] - 1);
        long long val = max_pref + a[i];
        res = max(res, val);
        tree.update(h[i], val);
    }
    cout << res;
    return 0;
}
