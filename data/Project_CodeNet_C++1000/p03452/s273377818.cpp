#include <bits/stdc++.h>
using ll = long long;
using namespace std;

const int inf = 1e9;
const ll linf = 1e18;

template<typename T = int>
class WeightedUnionFind
{
public:
    WeightedUnionFind(int n = 0, T unity = 0) : m_data(n, -1), m_weight(n, unity), m_count(n) {}

    int find(int x)
    {
        if (m_data[x] < 0) return x;

        int root = find(m_data[x]);
        m_weight[x] += m_weight[m_data[x]];
        return m_data[x] = root;
    }

    T weight(int x)
    {
        find(x);
        return m_weight[x];
    }

    bool unite(int x, int y, T w)
    {
        w += weight(x), w -= weight(y);
        x = find(x), y = find(y);
        if (x == y) return false;

        if (m_data[x] > m_data[y]) {
            swap(x, y);
            w = -w;
        }
        m_data[x] += m_data[y];
        m_data[y] = x;
        m_weight[y] = w;
        m_count--;
        return true;
    }

    bool same(int x, int y) { return find(x) == find(y); }

    T diff(int x, int y) { return weight(y) - weight(x); }

    int size(int x) { return -m_data[find(x)]; }

    int count(void) const { return m_count; }

private:
    vector<int> m_data;
    vector<T>   m_weight;
    int m_count; 
};

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);

    int n, m; cin >> n >> m;
    WeightedUnionFind<int> uf(n);
    for (int i = 0; i < m; i++) {
        int l, r, d; cin >> l >> r >> d; l--, r--; // 0-indexed
        if (!uf.same(l, r)) {
            uf.unite(l, r, d);
        } else {
            if (d != uf.diff(l, r)) {
                cout << "No" << endl;
                return 0;
            }
        }
    }
    cout << "Yes" << endl;
    return 0;
}