#include <bits/stdc++.h>
using namespace std;

struct graph {
    vector<vector<int>> gph;
    vector<int> indeg, outdeg;
    int vertex;
    graph(int N) : vertex(N) {
        gph.resize(vertex);
        indeg.resize(N);
        outdeg.resize(N);
    }
    // 有向グラフの構築
    void directed_update(int in, int out) {
        gph.at(in).emplace_back(out);
        indeg.at(in)++;
        outdeg.at(out)++;
    }
    // 無向グラフの構築
    void undirected_update(int x, int y) {
        gph.at(x).emplace_back(y);
        gph.at(y).emplace_back(x);
    }
};

class DAG {
  private:
    bool done_tsort;
    vector<int> used;
    graph g;

  public:
    vector<int> tsorted;
    vector<vector<int>> parents;
    DAG(const graph &_g)
        : done_tsort(false), g(_g), used(_g.outdeg), parents(_g.vertex) {
        tsorted.reserve(g.vertex);
    }
    void tsort() {
        if (done_tsort)
            return;
        queue<int> que;
        for (int i = 0; i < g.vertex; i++) {
            if (used[i] == 0)
                que.push(i);
        }
        while (!que.empty()) {
            int now = que.front();
            que.pop();
            tsorted.emplace_back(now);
            for (auto &&i : g.gph[now]) {
                used[i]--;
                parents[i].emplace_back(now);
                if (used[i] == 0)
                    que.push(i);
            }
        }
        return;
    }
    bool is_DAG() {
        if (done_tsort)
            return tsorted.size() == g.vertex;
        tsort();
        return is_DAG();
    }
};

int main() {
    int N, M;
    cin >> N >> M;
    auto g = graph(N);

    for (size_t i = 0; i < N + M - 1; i++) {
        int a, b;
        cin >> a >> b;
        g.directed_update(a - 1, b - 1);
    }
    auto dag = DAG(g);
    dag.tsort();
    vector<int> ans(N);
    for (int i = 0; i < N; i++) {
        int now = dag.tsorted[i];
        int mx  = dag.parents[now].size() == 0
                     ? -1
                     : dag.parents[now][dag.parents[now].size() - 1];
        ans[now] = mx + 1;
    }
    for (auto &&i : ans) {
        cout << i << '\n';
    }

    return 0;
}