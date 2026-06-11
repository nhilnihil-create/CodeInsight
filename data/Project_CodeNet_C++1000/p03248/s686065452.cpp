/*
    Author:zeke
    
    pass System Test!
    GET AC!!
*/
#include <iostream>
#include <queue>
#include <vector>
#include <iostream>
#include <vector>
#include <string>
#include <cassert>
#include <algorithm>
#include <functional>
#include <cmath>
#include <queue>
#include <set>
#include <stack>
#include <deque>
#include <map>
#include <iomanip>
#include <utility>
#include <stack>
#include <bitset>
using ll = long long;
using ld = long double;
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(), (x).end()
#define rep3(var, min, max) for (ll(var) = (min); (var) < (max); ++(var))
#define repi3(var, min, max) for (ll(var) = (max)-1; (var) + 1 > (min); --(var))
#define Mp(a, b) make_pair((a), (b))
#define F first
#define S second
#define Icin(s) \
    ll(s);      \
    cin >> (s);
#define Scin(s) \
    ll(s);      \
    cin >> (s);
template <class T>
bool chmax(T &a, const T &b)
{
    if (a < b)
    {
        a = b;
        return 1;
    }
    return 0;
}
template <class T>
bool chmin(T &a, const T &b)
{
    if (b < a)
    {
        a = b;
        return 1;
    }
    return 0;
}
typedef pair<ll, ll> P;
typedef vector<ll> V;
typedef vector<V> VV;
typedef vector<P> VP;
ll mod = 1e9 + 7;
ll MOD = 1e9 + 7;
ll INF = 1e18;
struct SegmentTree
{
    int n; // 最下段のノード数
    vector<int> node;
    int SIJK; // 最弱なやつ(INFとか-1とか)

public:
    SegmentTree(V v)
    {
        SIJK = (1ll << 31) - 1; // INFは最弱なので

        int sz = v.size();
        n = 1;
        while (n < sz)
            n *= 2; // n…最下段の横幅
        node.resize(2 * n - 1, SIJK);

        // 最下段に突っ込む
        for (int i = 0; i < sz; i++)
            node[(n - 1) + i] = v[i];

        // 最下段以外を更新していく
        for (int i = n - 2; i >= 0; i--)
        {
            node[i] = compare(node[i * 2 + 1], node[i * 2 + 2]);
        }
    }

    // 結合法則を満たすやつならなんでもいいよー。aかbを返す。
    int compare(int a, int b)
    {
        return min(a, b);
    }

    // i番目の要素をvalに変更する
    void update(int i, int val)
    {
        // まず最下段(2n-1)を変更する
        i += n - 1;
        node[i] = val;

        // 上に行きながら更新していく
        while (i > 0)
        {
            i = (i - 1) / 2; // 親へ
            node[i] = compare(node[2 * i + 1], node[2 * i + 2]);
        }
    }

    // [a,b) 中の結果を返す。[l,r)は対称区間の左端と右端。
    int find(int a, int b, int now = 0, int l = 0, int r = -1)
    {
        // 初期化
        if (r < 0)
            r = n;

        // 俺は関係ないとき -> 答えの邪魔にならない値を返す
        if (r <= a || b <= l)
            return SIJK;

        // 要求区間の中にノードがすっぽり入ってる → 計算候補として返す
        if (a <= l && r <= b)
            return node[now];

        // ノードの一部分だけ要求区間に入ってる → 子を再帰的に探索する
        int vl = find(a, b, 2 * now + 1, l, (l + r) / 2); // 子(左)
        int vr = find(a, b, 2 * now + 2, (l + r) / 2, r); // 子(右)
        return compare(vl, vr);
    }
};
int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    string s;
    cin>>s;
    ll n=s.size();
    if(s[0]-'0'==0){
        cout<<-1<<endl;
        return 0;
    }
    if(s[n-1]-'0'==1){
        cout<<-1<<endl;
        return 0;
    }
    rep(i,n-1){
        if(s[i]!=s[n-i-2]){
            cout<<-1<<endl;
            return 0;
        }
    }
    ll reg=n;
    for(int i=n-1;i>=1;i--){
        cout<<reg<<" "<<i<<endl;
        if(s[i-1]-'0'==1){
            reg=i;
        }
    }
}
