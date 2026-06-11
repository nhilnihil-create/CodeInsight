//---------------------------------------------------------------
#include <bits/stdc++.h>
using namespace std;
#include <iostream>
#include <vector>
#include <cstdlib>
#include <cmath>
#include <math.h>
#include <sstream>
#include <numeric>
#include <cctype>
#include <bitset>
#include <cassert>
#include<algorithm>
//---------------------------------------------------------------
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep1(i, n) for (int i = 1; i <= (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
#define SIZE 100005
#define INF 1e18
#define all(x) x.begin(),x.end()
#define fi first
#define se second
#define vec vector
using pint = pair<int,int>;
using ll = long long;
using vll = vector<ll>;
using vvll = vector<vector<ll>>;
//---------------------------------------------------------------
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};
const double pi = acos(-1);
//---------------------------------------------------------------

//↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓
struct UnionFind {
    vector<int> par; // par[i]:iの親の番号　(例) par[3] = 2 : 3の親が2

    UnionFind(int N) : par(N) { //最初は全てが根であるとして初期化
        for(int i = 0; i < N; i++) par[i] = -1;
    }

    int root(int x) { // データxが属する木の根を再帰で得る：root(x) = {xの木の根}
        if (par[x]<0) return x;
        return par[x] = root(par[x]);
    }

    void unite(int x, int y) { // xとyの木を併合
        int rx = root(x); //xの根をrx
        int ry = root(y); //yの根をry
        if (rx == ry) return; //xとyの根が同じ(=同じ木にある)時はそのま
        if(par[rx]>par[ry]) swap(rx,ry);
        par[rx]+=par[ry];
        par[ry] = rx; //xとyの根が同じでない(=同じ木にない)時：xの根rxをyの根ryにつける
    }

    bool same(int x, int y) { // 2つのデータx, yが属する木が同じならtrueを返す
        int rx = root(x);
        int ry = root(y);
        return rx == ry;
    }

    int size(int x){
        return -par[root(x)];
    }
};

int main() {
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

    ll n,m;
    cin>>n>>m;
    UnionFind uf(n);
    
    ll ans = n*(n-1)/2;
    vec<pint> v;
    rep(i,m){
        int a,b;
        cin>>a>>b;
        a--;b--;
        v.emplace_back(a,b);
    }

    vll res(m);

    rep(i,m){
        res[m-1-i]=ans;
        int a=v[m-1-i].fi;
        int b=v[m-1-i].se;
        if(uf.same(a,b)) {
            continue;
        }

        ans-=uf.size(a)*uf.size(b);
        uf.unite(a,b);
    }

    rep(i,m){
        cout<<res[i]<<endl;
    }
}