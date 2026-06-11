#include <iostream>
#include <algorithm>
#include <string>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <vector>
#include <queue>
#include <stack>
#include <cmath>
#include <map>
#include <iomanip>
#include <set>
#include <ctime>
#include <tuple>
#include <bitset>
#include <assert.h>
#include <deque>
using namespace std;

/*
using PAIR = pair<string, int>;
sort(sp.begin(), sp.end(), [](PAIR l, PAIR r){
        return l.first<r.first || (l.first==r.first && l.second > r.second);
        });
*/

typedef long long ll;

#define fi first
#define se second
#define rep(i, n) for (ll i = 0; i < n; i++)
#define debugA() cerr << "AAAAA" << endl
#define debug_() cerr << "-------------" << endl
#define debug(x) cerr << #x << ": " << x << endl
#define debug_vec(v)                   \
    for (int i = 0; i < v.size(); i++) \
    {                                  \
        cout << v[i] << " ";           \
    }                                  \
    cout << endl;
#define debug_vec2(v)                         \
    for (int i = 0; i < v.size(); i++)        \
    {                                         \
        for (int j = 0; j < v[i].size(); j++) \
        {                                     \
            cout << v[i][j] << " ";           \
        }                                     \
        cout << endl;                         \
    }

using Graph = vector<vector<int>>;
using P = pair<int, int>;
using P1 = pair<int, pair<int, int>>; // クラスカル法とかで、{cost, {from, to}}的に使う。
const int INF = 1001001001;
const double pi = acos(-1);

class UnionFind
{
public:
    // 親の番号を格納する。親だった場合は -(その集合のサイズ)とする。
    vector<int> Parent;

    // 作るときはParentの値を全て-1にする。
    UnionFind(int N)
    {
        Parent = vector<int>(N, -1);
    }

    // Aがどのグループに所属しているか調べる。
    int root(int A)
    {
        if (Parent[A] < 0)
            return A;
        return Parent[A] = root(Parent[A]);
    }

    // 自分のいる頂点の数をイラべる。
    int size(int A)
    {
        return -Parent[root(A)]; // 親を取ってきたい。
    }

    // AとBをくっつける。
    bool unite(int A, int B)
    {
        // root(A)をroot(B)にくっつける。
        A = root(A);
        B = root(B);
        if (A == B)
        {
            return false;
        }
        // 大きい方(A)に小さい方(B)をくっつけたい。
        // 大小が逆ならひっくり返す。
        if (size(A) < size(B))
        {
            swap(A, B);
        }

        // Aのサイズを更新する。
        Parent[A] += Parent[B];
        // Bの親をAに変更する。
        Parent[B] = A;
        return true;
    }
};

int main()
{
    int n, m;
    cin >> n >> m;
    vector<pair<int, int>> b(m);
    for (int i = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y;
        x--;
        y--;
        b[i] = {x, y};
    }
    vector<ll> ans(m, 0);
    UnionFind tree(n);
    ans[m - 1] = ll(n) * ll((n - 1)) / 2;
    for (int i = 0; i < m - 1; i++)
    {
        int x = b[m - 1 - i].fi;
        int y = b[m - 1 - i].se;
        if (tree.root(x) == tree.root(y))
        {
            ans[m - 2 - i] = ans[m - 1 - i];
        }
        else
        {
            ans[m - 2 - i] = ans[m - 1 - i] - tree.size(x) * tree.size(y);
            tree.unite(x, y);
        }
    }
    for (int i = 0; i < m; i++)
    {
        cout << ans[i] << endl;
    }

    return 0;
}
