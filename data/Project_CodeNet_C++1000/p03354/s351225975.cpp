#include <bits/stdc++.h>
using namespace std;

struct UnionFind
{
    vector<int> par; //par[i]:iの親の番号

    //初めは全てが根であるとして初期化する
    UnionFind(int N): par(N)
    {
        for (int i=0; i<N; i++) par[i]=i;
    }

    int root(int x)
    {
        if (par[x] == x) return x;
        return par[x] = root(par[x]);
    }

    void unite(int x, int y)
    {
        int rx = root(x);
        int ry = root(y);
        if (rx == ry) return;
        par[rx] = ry;
    }

    bool same(int x, int y)
    {
        int rx = root(x);
        int ry = root(y);
        return rx == ry;
    }
};


int main()
{
    int N, M;
    cin >> N >> M;
    vector<int> P(N);
    for (int i=0; i<N; i++) cin >> P[i];
    
    UnionFind Tree(N);

    for (int i=0; i<M; i++)
    {
        int x, y;
        cin >> x >> y;
        Tree.unite(x-1, y-1);
    }
    int answer = 0;
    for (int i=0; i<N; i++)
    {
        if (i+1==P[i]) answer++;
        else if (Tree.same(i, P[i]-1)) answer++;
    }
    cout << answer << endl;
}