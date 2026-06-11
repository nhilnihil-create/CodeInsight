#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <stack>
#include <queue>
#include <numeric>
#include <iomanip>
#include <map>
#include <set>
#include <deque>
#include <utility>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < n; i++)
#define repk(i, k, n) for (int i = k; i < n; i++)
#define MOD 1e9 + 7
#define INF 1e9
#define PIE 3.14159265358979323

template <class T>
inline bool chmin(T &a, T b) {if (a > b) {a = b; return true;} return false;}
template <class T>
inline bool chmax(T &a, T b) {if (a < b) {a = b; return true;} return false;}
template <class T>
T GCD(T a, T b) {if (b == 0) return a; else return GCD(b, a % b);}
template <class T>
inline T LCM(T a, T b) { return (a * b) / GCD(a, b);}

struct Union_find
{
    vector<int> par;
    vector<int> rank;

    Union_find(int n) : par(n), rank(n)
    {
        for (int i = 0; i < n; i++)
        {
            par[i] = i;
            rank[i] = 0;
        }
    }

    int root(int x)
    {
        return par[x] == x ? x : par[x] = root(par[x]);
    }

    bool same(int x, int y)
    {
        return root(x) == root(y);
    }

    void unite(int x, int y)
    {
        x = root(x);
        y = root(y);
        //根にのみランクが保持されればいい
        if (rank[x] < rank[y])
            par[x] = y;
        else
        {
            par[y] = x;
            if (rank[x] == rank[y])
                rank[x]++;
        }
        return;
    }
};

int main(){
    int n, m;
    cin >> n >> m;
    vector<int> p(n);
    rep(i, n) cin >> p[i];
    Union_find uf(n);
    int x, y;
    rep(i, m){
        cin >> x >> y;
        x--;
        y--;
        uf.unite(x, y);
    }
    int count = 0;
    rep(i, n){
        if (uf.same(i, p[i]-1))
            count++;
    }
    cout << count << endl;
}