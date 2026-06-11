#define _USE_MATH_DEFINES
#include <math.h>
#include <algorithm>
#include <cctype>
#include <cmath>
#include <deque>
#include <iomanip>
#include <iostream>
#include <map>
#include <numeric>
#include <set>
#include <stack>
#include <string>
#include <vector>

using namespace std;
using LLONG = long long;
const LLONG MOD = 1000000007;

// Union-Find木（素集合森：Disjoint-Set Forest）
// グループ分けを木構造で管理するデータ構造
class UnionFindTree
{
private:
    // 各ノードの親ノード番号リスト
    vector<int> m_parents;

public:
    // コンストラクタ
    UnionFindTree(const int N) : m_parents(N)
    {
        // 最初は全ての親が自分自身＝根であるとして初期化
        for (int i = 0; i < N; ++i) m_parents[i] = i;
    }

    // データvが属する木の根を返す
    const int Root(const int v)
    {
        if (m_parents[v] == v) return v;
        return m_parents[v] = Root(m_parents[v]);
    }

    // データv1とv2の木を統合する
    void Unite(const int v1, const int v2)
    {
        int r1 = Root(v1), r2 = Root(v2);
        if (r1 == r2) return;
        m_parents[r1] = r2;
    }

    // ２つのデータが同じ木に属するかどうか判定
    const bool AreInSameTree(const int v1, const int v2)
    {
        return Root(v1) == Root(v2);
    }
};

int main()
{
    int N, M; cin >> N >> M;
    vector<pair<int, int>> edges;
    for (int i = 0; i < M; ++i)
    {
        int u, v; cin >> u >> v; --u; --v;
        edges.push_back({ u, v });
    }
    int ans = 0;
    for (int i = 0; i < M; ++i)
    {
        UnionFindTree uft(N);
        for (int j = 0; j < M; ++j)
        {
            if (i != j)
            {
                uft.Unite(edges[j].first, edges[j].second);
            }
        }
        if (!uft.AreInSameTree(edges[i].first, edges[i].second))
        {
            ++ans;
        }
    }
    cout << ans << endl;
}