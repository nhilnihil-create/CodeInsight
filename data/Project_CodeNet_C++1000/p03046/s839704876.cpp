#ifdef LOCAL
#include "libs/debug/print_list.hpp"
#define debug(x) (cout << # x ": " << x << endl)
#define dev(v, m, n) for(int i=0;i<n;++i){for(int j=0;j<m;++j){cout<<"|"<<v[j][i];}cout<<"|"<<endl;}
#else
#define debug(x) ;
#define dev(v, m, n) ;
#endif

// :----------------------------------------

#include <algorithm>
#include <cassert>
#include <cmath>
#include <deque>
#include <iomanip>
#include <iostream>
#include <list>
#include <numeric>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <vector>

using namespace std;

#define int long long int
#define rep(i, n) for (int i = 0; i < n; ++i)
#define all(x) (x).begin(), (x).end()
#define capi(x) int x;cin>>x
#define fastio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

using vi = vector<int>;
using pi = pair<int, int>;
using vp = vector<pi>;
using Graph = vector<vector<int>>;

template<class T>bool chmax(T &a, const T &b){if(a<b){a=b;return 1;}return 0;}
template<class T>bool chmin(T &a, const T &b){if(b<a){a=b;return 1;}return 0;}

#define P (1'000'000'007)

signed main() {
    int m, k;
    cin >> m >> k;

    if (m == 1) {
        if (k == 0) {
            cout << "0 0 1 1";
        } else {
            cout << -1;
        }
    } else if (k < (1 << m)) {
        list<int> li;
        li.push_back(k);
        rep (i, 1 << m) {
            if (i == k) continue;
            li.push_back(i);
            li.push_front(i);
        }
        li.push_back(k);

        bool is_initial = true;
        for (auto x: li) {
            if (!is_initial) {
                cout << " ";
            } else {
                is_initial = false;
            }
            cout << x;
        }
    } else {
        cout << -1;
    }

    return 0;
}
