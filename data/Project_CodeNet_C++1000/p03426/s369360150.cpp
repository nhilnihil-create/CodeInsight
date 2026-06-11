#include <algorithm>
#include <deque>
#include <iomanip>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <tuple>
#include <vector>

using namespace std;

typedef long long ll;
// constexpr ll MOD = 998244353;
constexpr ll MOD = 1000000007;

// struct UnionFind {
//     vector<int> par;
    
//     UnionFind(int N): par(N) {
//         for (int i=0;i<N;i++) par[i] = i;
//     }

//     int root(int x) {
//         if (par[x] == x) return x;
//         else return par[x] = root(par[x]);
//     }

//     void unite(int x, int y) {
//         int rx = root(x);
//         int ry = root(y);
//         if (rx == ry) return;
//         par[rx] = ry;
//     }

//     bool same(int x, int y) {
//         int rx = root(x);
//         int ry = root(y);
//         return rx == ry;
//     }
// };

int main(void) {
    int H, W, D, Q;
    int A[310][310];
    int L[100010], R[100010];
    cin >> H >> W >> D;
    for (int i=0;i<H;i++) for (int j=0;j<W;j++) cin >> A[i][j];
    cin >> Q;
    for (int k=0;k<Q;k++) cin >> L[k] >> R[k];

    map<int,pair<int,int>> M;
    for (int i=0;i<H;i++) for (int j=0;j<W;j++) {
        M[A[i][j]] = make_pair(i,j);
    }

    vector<int> score(H*W+1,0);
    for (int i=D+1;i<=H*W;i++) {
        auto src = M[i-D], dest = M[i];
        score[i] = score[i-D] + abs(dest.first - src.first) + abs(dest.second - src.second);
    }

    for (int k=0;k<Q;k++) {
        cout << score[R[k]] - score[L[k]] << endl;
    }

    return 0;
}
