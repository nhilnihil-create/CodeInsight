#include <iostream>
#include <queue>
#include <map>
#include <cmath>
#include <algorithm>
#include <queue>
#include <cstdarg>
#include <set>
#include <limits>
#include <iomanip>

using namespace std;
#define INF 2e9 + 9
#define MOD 1000000007
#define ALL(v) v.begin() , v.end()
#define Int int64_t
#define pll pair<Int,Int>
template<class T> using pql = priority_queue<T, vector<T>>;
template<class T> using pq = priority_queue<T, vector<T>, greater<T>>;
#define ll(n) Int n; cin >> n;
#define LL(...) Int __VA_ARGS___; cin >> __VA_ARGS___;
#define OUT(...) cout << __VA_ARGS___;
#define RP(n, i, s) for(Int i = s ;i < n ;i++)
#define REP(n, i) for (Int i = 0; i < n; i++)
#define REPe(n, i) for (Int i = 1; i <= n; i++)
#define RPe(n, i, s) for (Int i = s; i <= n; i++)
#define upd_max(maxer, updater) if (maxer < updater) maxer = updater;
#define upd_min(miner, updater) if (miner > updater) miner = updater;
#ifdef DEBUG

#else

#    pragma GCC optimize("O3,no-stack-protector")
#    pragma GCC optimize("unroll-loops")

#    if __cplusplus < 201703L
#        pragma GCC target("avx")
#    else
#        pragma GCC target("avx2")
#    endif

#endif
// 実数の場合
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

void ansYes(bool flag){
    if (flag) cout << "Yes" << endl; else  cout << "No" << endl;
}

void ansYES(bool flag){
    if (flag) cout << "YES" << endl; else  cout << "NO" << endl;
}

struct node {
    Int to;
    Int length;
};


Int gcd(Int a, Int b)
{
    if (a%b == 0)
    {
        return(b);
    }
    else
    {
        return(gcd(b, a%b));
    }
}

vector<Int> divisor(Int n) {
    vector<Int> ret;
    for (Int i = 1; i * i <= n; i++) {
        if (n % i == 0) {
            ret.push_back(i);
            if (i * i != n) ret.push_back(n / i);
        }
    }
    return (ret);
}

Int dx8[8] = {0, -1, -1, -1, 0, 1, 1, 1};
Int dy8[8] = {-1, -1, 0, 1, 1, 1, 0, -1};



//UnionFind群
/*
class UnionFind {
protected:
    vector<Int> par;
    vector<Int> data;
    Int cnt;
public:
    UnionFind() : par(1), data(1), cnt(1) {};
    UnionFind(Int N);
    Int root(Int x);
    Int marge(Int x, Int y);
    bool same(Int x, Int y);
    Int add();
    Int add(Int x);
    Int solve();
    inline Int getSize(Int x) { return data.at(root(x)); };
};

UnionFind::UnionFind(Int N) : par(N), data(N), cnt(N) {
    for (Int i = 0; i < N; i++) {
        par.at(i) = -1;
        data.at(i) = 1;
    }
}


Int UnionFind::root(Int x) {
    if (par.at(x) == -1) return x;
    return par.at(x) = root(par.at(x)); // 経路圧縮
}

Int UnionFind::marge(Int x, Int y) {
    Int rx = root(x);
    Int ry = root(y);
    if (rx == ry) return rx;
    else { // ノード数の少ない方に接続
        if (data.at(rx) < data.at(ry)) swap(rx, ry);
        par.at(ry) = rx;
        data.at(rx) += data.at(ry);
        return rx;
    }
    return rx;
}

bool UnionFind::same(Int x, Int y) {
    return root(x) == root(y);
}

Int UnionFind::add() {
    par.push_back(cnt);
    cnt++;
    return cnt - 1;
}

Int UnionFind::add(Int x) {
    par.push_back(cnt);
    cnt++;
    return marge(x, cnt);
}

Int UnionFind::solve() {
    for (Int i = 0; i < cnt;i++) {
        if (par.at(i) == -1) {

        }
    }
}*/

/*
Int dfs(Int par, Int maxs, bool ans) {
    if (mita.at(par) == 1) return 0;
    if (maxs > h.at(par)) {
        maxs = h.at(par);
        ans = true;
    }else if (maxs == h.at(par)){
        ans = false;
    }

    Int maxer = 0;
    for (auto z : to[par]){
        mita.at(par) = 1;
        maxer = dfs(z,maxs,ans);
    }
}*/

int main() {
    Int n;
    cin >> n;
    vector<Int> a(n);
    REP(n,i){
        Int x;
        cin >> a.at(i);
    }
    sort(a.begin(),a.end(),greater<>());
    Int ans = a.at(0);
    for (Int i = 1; i < n; i++) {
        ans = gcd(ans, a.at(i));
    }
    cout << ans << endl;
}