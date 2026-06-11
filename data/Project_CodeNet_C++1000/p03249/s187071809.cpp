#include <algorithm>
#include <bitset>
#include <complex>
#include <deque>
#include <exception>
#include <fstream>
#include <functional>
#include <iomanip>
#include <ios>
#include <iosfwd>
#include <iostream>
#include <istream>
#include <iterator>
#include <limits>
#include <list>
#include <locale>
#include <map>
#include <memory>
#include <new>
#include <numeric>
#include <ostream>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <stdexcept>
#include <streambuf>
#include <string>
#include <typeinfo>
#include <utility>
#include <valarray>
#include <vector>
#include <climits>

#define rep(i, m, n) for(int i=int(m);i<int(n);i++)
#define all(c) begin(c),end(c)

template<typename T1, typename T2>
inline void chmin(T1 &a, T2 b) { if (a > b) a = b; }

template<typename T1, typename T2>
inline void chmax(T1 &a, T2 b) { if (a < b) a = b; }

//改造
typedef long long int ll;
using namespace std;
#define INF (1 << 30) - 1
#define INFl (ll)5e15
#define dump(x)  cerr << #x << " = " << (x) << endl
#define MOD 1000000007


//ここから編集する


int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int N;
    cin >> N;

    vector<ll> D(N);
    map<ll, int> Dtov;
    rep(i, 0, N) cin >> D[i];
    rep(i, 0, N) Dtov[D[i]] = i + 1;

    sort(D.rbegin(), D.rend());

    vector<vector<int> > G(N + 1, vector<int>());//自分の親
    vector<vector<int> > rG(N + 1, vector<int>());//自分の子供
    vector<int> childs(N + 1, 1); //部分木の数

    for (int i = 0; i < N - 1; ++i) {
//        ll dec = N - 2 * (1 + rG[Dtov[D[i]]].size());
        ll dec = N - 2 * childs[Dtov[D[i]]];
//        if (find(all(D), D[i] - dec) == D.end()) {
//            cout << -1 << endl;
//            return 0;
//        }

        if (*lower_bound(all(D), D[i] - dec) == D[i] - dec) {
            cout << -1 << endl;
            return 0;
        }

        G[Dtov[D[i]]].push_back(Dtov[D[i] - dec]);
        rG[Dtov[D[i] - dec]].push_back(Dtov[D[i]]);
        childs[Dtov[D[i] - dec]] += childs[Dtov[D[i]]];
    }

    function<ll(int, int)> treesize = [&](int v, int dist) {
        ll ret = dist;

        for (auto e : rG[v]) {
            ret += treesize(e, dist + 1);
        }

        return ret;
    };

    ll min_tree_size = treesize(Dtov[D.back()], 0);
    if (min_tree_size != D.back()) {
        cout << -1 << endl;
        return 0;
    }

    for (int i = 1; i <= N; ++i) {
        for (auto e : G[i]) {
            cout << i << " " << e << endl;
        }
    }

    return 0;
}
