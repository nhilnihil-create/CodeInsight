#include <bits/stdc++.h>
#include <math.h>

using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
typedef long long ll;
using Graph = vector<vector<int>>;
typedef long long ll;
typedef pair<int, int> P;

const int MOD = 1000000007;
const int INF_32 = 1LL << 30;
const int64_t INF_64 = 1LL << 60;

template <typename A, size_t N, typename T>
void Fill(A (&array)[N], const T& val)
{
    std::fill((T*)array, (T*)(array + N), val);
}

struct UnionFind {
    vector<int> d;
    UnionFind(int n = 0)
        : d(n, -1)
    {
    }
    int find(int x)
    {
        if (d[x] < 0)
            return x;
        return d[x] = find(d[x]);
    }
    bool unite(int x, int y)
    {
        x = find(x);
        y = find(y);
        if (x == y)
            return false;
        if (d[x] > d[y])
            swap(x, y);
        d[x] += d[y];
        d[y] = x;
        return true;
    }
    bool same(int x, int y) { return find(x) == find(y); }
    int size(int x) { return -d[find(x)]; }
};

int main()
{
    int N, M;
    cin >> N >> M;
    UnionFind uf(N);
    for (int i = 0; i < M; i++) {
        int x, y, z;
        cin >> x >> y >> z;
        x--, y--;
        uf.unite(x, y);
    }

    set<int> s;
    for (int i = 0; i < N; i++) {
        s.insert(uf.find(i));
    }

    cout << s.size() << endl;
    return 0;
}