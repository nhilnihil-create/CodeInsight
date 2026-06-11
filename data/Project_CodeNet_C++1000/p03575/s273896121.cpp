#include <bits/stdc++.h>
using namespace std;
using ll = long long;


class UnionFindTree
{
private:
    vector<int> parent;
    vector<int> rank;
public:
    UnionFindTree(int n)
    {
        init(n);
    }

    void init(int n)
    {
        parent.resize(n);
        rank.resize(n, 0);

        for (int i = 0; i < n; i++)
        {
            parent[i] = i;
        }
    }

    // find root node
    int find(int x)
    {
        if (parent[x] == x)
        {
            return x;
        }
        else
        {
            return parent[x] = find(parent[x]);
        }
    }

    void unite(int x, int y)
    {
        x = find(x);
        y = find(y);

        // already in the same tree.
        if (x == y)
            return;

        if (rank[x] < rank[y])
        {
            parent[x] = y;
        }
        else
        {
            parent[y] = x;
            if (rank[x] == rank[y])
            {
                rank[x]++;
            }
        }
    }

    bool same(int x, int y)
    {
        return (find(x) == find(y));
    }
};

int main(void)
{
    int N, M;
    cin >> N >> M;

    using pii = pair<int,int>;

    vector<pii> edge(M);

    for (int i = 0; i < M; i++)
    {
        int a, b;
        cin >> a >> b;
        a--; b--;
        edge[i].first = a;
        edge[i].second = b;
    }

    int ans = 0;

    for (int i = 0; i < M; i++)
    {
        UnionFindTree uft(N);

        for (int j = 0; j < M; j++)
        {
            if(i != j && !uft.same(edge[j].first, edge[j].second)){
                uft.unite(edge[j].first, edge[j].second);
            }
        }

        set<int> s;

        for (int j = 0; j < N; j++)
        {
            if(uft.find(j) == j) s.insert(j);
        }

        if(s.size() > 1) ans++;
    }

    cout << ans << endl;

    return 0;
}
