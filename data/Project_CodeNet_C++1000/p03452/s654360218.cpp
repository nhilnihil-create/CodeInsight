#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define FOR(i, s, e) for (int i = (int)(s); i <= (int)(e); i++)
#define printYesNo(is_ok) puts(is_ok ? "Yes" : "No");
#define SORT(v) sort(v.begin(), v.end());
#define RSORT(v) sort(v.rbegin(), v.rend());
#define REVERSE(v) reverse(v.begin(), v.end());

template <typename T>
void printlnVector(T v)
{
    rep(i, v.size())
    {
        cout << v[i] << endl;
    }
}

template <typename T>
void printVector(T v)
{
    rep(i, v.size())
    {
        cout << v[i] << " ";
    }
    cout << endl;
}

struct WeightedUnionFind
{
    vector<pair<int, int>> d;
    WeightedUnionFind(int n = 0) : d(n, make_pair(-1, 0)) {}
    int find(int x)
    {
        if (d[x].first < 0)
            return x;

        int r = find(d[x].first);
        d[x].second += d[d[x].first].second;
        return d[x].first = r;
    }
    bool unite(int x, int y, int l)
    {
        l = dist(x) + l - dist(y);
        x = find(x);
        y = find(y);
        if (x == y)
            return false;
        if (d[x].first > d[y].first)
        {
            swap(x, y);
            l *= -1;
        }
        d[x].first += d[y].first;
        d[y].first = x;
        d[y].second = l;
        return true;
    }
    bool same(int x, int y) { return find(x) == find(y); }
    int size(int x) { return -(d[find(x)].first); }
    int dist(int x)
    {
        find(x);
        return d[x].second;
    }
    int diff(int x, int y) { return dist(y) - dist(x); }
};

int main()
{
    int N, M;
    cin >> N >> M;
    WeightedUnionFind uf(N);
    bool is_ok = true;
    rep(i, M)
    {
        int L, R, D;
        cin >> L >> R >> D;
        --L;
        --R;
        if (uf.same(L, R))
        {
            if (uf.diff(L, R) != D)
                is_ok = false;
        }
        else
        {
            uf.unite(L, R, D);
        }
    }

    printYesNo(is_ok);
    return 0;
}
