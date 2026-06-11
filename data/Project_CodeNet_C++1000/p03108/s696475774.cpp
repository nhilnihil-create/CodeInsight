#define _USE_MATH_DEFINES
#include <algorithm>
#include <array>
#include <bitset>
#include <cassert>
#include <cctype>
#include <climits>
#include <clocale>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <deque>
#include <fstream>
#include <functional>
#include <iomanip>
#include <iostream>
#include <iterator>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <regex>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>

const int MOD = 1'000'000'007; 
const int INF = 1'000'000'000; //1e9
const int NIL = -1;
const long long LINF = 1'000'000'000'000'000'000; // 1e18
const long double EPS = 1E-10;

template<class T, class S> inline bool chmax(T &a, const S &b){
    if(a < b){
        a = b; return true;
    }
    return false;
}
template<class T, class S> inline bool chmin(T &a, const S &b){
    if(b < a){
        a = b; return true;
    }
    return false;
}

class UnionFind{
    std::vector<int> par;
    std::vector<int> rank;
    std::vector<int> membnum;

public:
    UnionFind(){}
    UnionFind(int n): par(n), rank(n), membnum(n){
        for(int i(0); i < n; ++i){
            par[i] = i;
            rank[i] = 0;
            membnum[i] = 1;
        }
    }

    void resize(int n){
        int m(par.size());
        par.resize(n);
        rank.resize(n, 0);
        membnum.resize(n, 1);
        for(int i(m); i < n; ++i) par[i] = i;
    }

    int find(int x){
        if(x == par[x]) return x;
        else return par[x] = find(par[x]);
    }

    bool unit(int x, int y){
        x = find(x);
        y = find(y);
        if(x == y) return false;

        if(rank[x] < rank[y]){
            par[x] = y;
            membnum[y] += membnum[x];
        }else{
            par[y] = x;
            if(rank[x] == rank[y]) ++rank[x];
            membnum[x] += membnum[y];
        }
        return true;
    }

    bool same(int x, int y){
        return find(x) == find(y);
    }

    int howmany(int x){ //同じグループに属すものの個数(自分を含む)
        return membnum[find(x)];
    }
};





int main(){
    int N, M; std::cin >> N >> M;
    UnionFind uf(N);
    std::vector<int> a(M), b(M);
    for(int i(0); i < M; ++i){
        std::cin >> a[i] >> b[i];
        --a[i]; --b[i];
    }
    std::vector<long long> ans(M);
    long long cnt((long long)N * (N - 1) / 2);
    ans[M-1] = cnt;
    for(int i(M-1); i > 0; --i){
        if(!uf.same(a[i], b[i])){
            long long n1(uf.howmany(a[i])), n2(uf.howmany(b[i]));
            cnt -= n1 * n2;
            uf.unit(a[i], b[i]);
        }
        ans[i-1] = cnt;
    }
    for(int i(0); i < M; ++i){
        std::cout << ans[i] << "\n";
    }
    return 0;
}
