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
//     vector<ll> par;
//     vector<ll> siz;
    
//     UnionFind(ll N): par(N), siz(N,1LL) {
//         for (ll i=0;i<N;i++) par[i] = i;
//     }

//     ll root(ll x) {
//         if (par[x] == x) return x;
//         else return par[x] = root(par[x]);
//     }

//     void unite(ll x, ll y) {
//         ll rx = root(x);
//         ll ry = root(y);
//         if (rx == ry) return;
//         par[rx] = ry;
//         siz[ry] += siz[rx];
//     }

//     bool same(ll x, ll y) {
//         ll rx = root(x);
//         ll ry = root(y);
//         return rx == ry;
//     }

//     ll size(ll x) {
//         return siz[root(x)];
//     }
// };

int main(void) {
    int N, v[100010];
    cin >> N;
    for (int i=0;i<N;i++) cin >> v[i];

    vector<int> O(100010,0),E(100010,0);
    for (int i=0;i<N;i+=2) O[v[i]]++;
    for (int i=1;i<N;i+=2) E[v[i]]++;

    multimap<int,int,greater<int>> Om, Em;
    Om.emplace(0,0), Em.emplace(0,0);
    for (int i=0;i<100010;i++) {
        if (O[i]) Om.emplace(O[i],i);
        if (E[i]) Em.emplace(E[i],i);
    } // first: count, second: number
    // for (auto itr: Om) {
    //     cout << itr.first << ": " << itr.second << endl;
    // }
    // for (auto itr: Em) {
    //     cout << itr.first << ": " << itr.second << endl;
    // }
    auto oitr = Om.begin(), eitr = Em.begin();
    bool flag = false;
    while (oitr->second == eitr->second) {
        oitr++; eitr++;
        flag = true;
        if (oitr == Om.end()) break;
    }
    if (oitr == Om.end()) {
        oitr = Om.begin(), eitr = Em.begin();
        eitr++;
    } else if (flag) {
        if (oitr->first < eitr->first) {
            oitr = Om.begin(), eitr = Em.begin();
            eitr++;
        } else {
            oitr = Om.begin(), eitr = Em.begin();
            oitr++;
        }
    }
    cout << N - oitr->first - eitr->first << endl;

    return 0;
}
