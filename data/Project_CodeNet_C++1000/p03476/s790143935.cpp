#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
#define rep(i,N) for(int i = 0; i < (N); i++)
#define erep(i,N) for(int i = N - 1; i >= 0; i--)
const ll INF = 1000000000;
//const ll MOD = 1000000007;
const ld PI = (acos(-1));
using Graph = vector<vector<int>>;
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true;} return false;}
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true;} return false;}
typedef pair<int, int> P;
typedef pair<ll,ll> PLL;
double rad(double a) {return a * 180 / PI;}

struct UnionFind {
    vector<int> par; // par[i]:iの親の番号 (例) par[3] = 2 : 3の親が2

    UnionFind(int N) : par(N) { //最初は全てが根であるとして初期化
        for(int i = 0; i < N; i++) par[i] = i;
    }

    int root(int x) { // データxが属する木の根を再帰で得る：root(x) = {xの木の根}
        if (par[x] == x) return x;
        return par[x] = root(par[x]);
    }

    void unite(int x, int y) { // xとyの木を併合
        int rx = root(x); //xの根をrx
        int ry = root(y); //yの根をry
        if (rx == ry) return; //xとyの根が同じ(=同じ木にある)時はそのまま
        par[rx] = ry; //xとyの根が同じでない(=同じ木にない)時：xの根rxをyの根ryにつける
    }

    bool same(int x, int y) { // 2つのデータx, yが属する木が同じならtrueを返す
        int rx = root(x);
        int ry = root(y);
        return rx == ry;
    }
};

//dpTable
//int dp[100050];

int main(){
    int Q;
    cin >> Q;
    vector<int> l(Q);
    vector<int> r(Q);
    rep (i,Q) cin >> l.at(i) >> r.at(i);
    vector<int> rui(100050,0);
    for (int i = 1; i < 100000; i += 2) {
        if (i != 1) {
            bool hoge = false,huga = false;
            for (int j = 2; j <= sqrt(i); j++) {
                if (i % j == 0) hoge = true;
            }
            for (int j = 2; j <= sqrt((i + 1) / 2); j++) {
                if (((i + 1) / 2) % j == 0) huga = true;
            }
            if (!(hoge) && !(huga)) rui.at(i)++;
        }
    }
    for (int i = 1; i < 100050; i++) rui.at(i) += rui.at(i - 1);
    for (int i = 0; i < Q; i++) {
        cout << rui.at(r.at(i)) - rui.at(l.at(i) - 1) << endl;
    }
    return 0;
}