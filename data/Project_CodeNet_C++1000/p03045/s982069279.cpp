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
    cout << #v << endl;                \
    for (int i = 0; i < v.size(); i++) \
    {                                  \
        cout << v[i] << " ";           \
    }                                  \
    cout << endl;
#define debug_vec2(v)                         \
    cout << #v << endl;                       \
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
const ll INF = 1001001001001001001;
const double pi = acos(-1);

// 使い方
// UnionFind tree(N);
// struct UnionFind
// {
//     vector<int> par; // par[i]:iの親の番号　(例) par[3] = 2 : 3の親が2

//     UnionFind(int N) : par(N)
//     { //最初は全てが根であるとして初期化
//         for (int i = 0; i < N; i++)
//             par[i] = i;
//     }

//     int root(int x)
//     { // データxが属する木の根を再帰で得る：root(x) = {xの木の根}
//         if (par[x] == x)
//             return x;
//         return par[x] = root(par[x]);
//     }

//     void unite(int x, int y)
//     {                     // xとyの木を併合
//         int rx = root(x); //xの根をrx
//         int ry = root(y); //yの根をry
//         if (rx == ry)
//             return;   //xとyの根が同じ(=同じ木にある)時はそのまま
//         par[rx] = ry; //xとyの根が同じでない(=同じ木にない)時：xの根rxをyの根ryにつける
//     }

//     bool same(int x, int y)
//     { // 2つのデータx, yが属する木が同じならtrueを返す
//         int rx = root(x);
//         int ry = root(y);
//         return rx == ry;
//     }
// };

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

    // 自分のいる頂点の数を調べる。
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

    UnionFind tree(n);
    for (int i = 0; i < m; i++)
    {
        int x, y, z;
        cin >> x >> y >> z;
        x--;
        y--;
        tree.unite(x, y);
    }
    set<int> st;
    for (int i = 0; i < n; i++)
    {
        st.insert(tree.root(i));
    }
    cout << st.size() << endl;

    return 0;
}
