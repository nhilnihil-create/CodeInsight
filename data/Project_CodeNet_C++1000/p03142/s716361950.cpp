#include <bits/stdc++.h>
#define BIT(n) (1LL << (n))
#define REP(i, n) for (int i = 0; i < n; i++)
#define REPB(i, n) for (int i = 0; i < BIT(n); i++)
#define REPS(i, x) for (int i = 1; i <= (int)(x); i++)
#define REPR(i, n) for (int i = n; i >= 0; i--)
#define FOR(i, m, n) for (int i = m; i < n; i++)
#define FORA(i, v) for (auto &&i : v)
#define FORS(i, m, n) for (int i = m; i <= n; i++)
#define INF 2e9
#define MOD (1000000007)
#define EPS 1e-9
#define ALL(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
typedef long long int lli;
vector<vector<int>> graph;
vector<vector<int>> graphI;
vector<bool> visited;
vector<vector<pair<int, int>>> visitedList;
vector<pair<int, int>> ans;
vector<int> d;
vector<int> old;
int N, M;

//トポロジカル順序
/*
トポロジカル順序に関する問題であることは漠然とわかったが
その後が続かなかった。
特にグラフの辺を削除する部分にコストがかかると思ってしまった。
実際には、グラフを削除する必要はなかった。
stackを使うのが本質的なポイントかもしれない。
トポロジカル順序を求めるアルゴリズムは
 */
int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> N >> M;
    graph.resize(N + 1, vector<int>());
    graphI.resize(N + 1, vector<int>());
    visited.resize(N + 1);
    //頂点とその親を保存する.
    visitedList.resize(N + 1, vector<pair<int, int>>());
    d.assign(N + 1, 0);
    old.assign(N + 1, 0);
    REP(i, N - 1 + M)
    {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graphI[b].push_back(a);
        //入次数
        d[b]++;
    }

    stack<pair<int, int>> st;
    REPS(i, N)
    {
        if (d[i] == 0)
            st.push(make_pair(i, -1));
    }
    vector<pair<int, int>> ans;
    while (st.size())
    {
        //cout << st.size() << endl;
        int i = st.top().first;
        int j = st.top().second;
        //cout << i << " " << j << endl;
        st.pop();
        //me parent
        ans.emplace_back(i, j);
        old[i] = ans.size();
        for (auto &&v : graph[i])
        {
            d[v]--;
            if (d[v] == 0)
                st.push(make_pair(v, i));
        }
    }

    sort(ALL(ans));
    FORA(i, ans)
    {
        //cout << ((i.second == -1) ? 0 : i.second) << "\n";
        if (i.second == -1)
        {
            cout << 0 << "\n";
        }
        else
        {
            int maxV = -1, maxIndex = -1;
            FORA(v, graphI[i.first])
            {
                if (old[v] > maxV)
                {
                    maxV = old[v];
                    maxIndex = v;
                }
            }
            cout << maxIndex << "\n";
        }
    }
    //最大という制約よりsecondを直接出力しても問題ない。次数を0にするのはもっとも近い頂点になる。
    /*  FORA(i, ans)
    {
        cout << i.first << " " << i.second << "\n";
    }*/
}