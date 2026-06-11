#include <iostream>
#include <array>
#include <algorithm>
#include <vector>
#include <bitset>
#include <set>
#include <unordered_set>
#include <cmath>
#include <complex>
#include <deque>
#include <iterator>
#include <numeric>
#include <map>
#include <unordered_map>
#include <queue>
#include <stack>
#include <string>
#include <tuple>
#include <utility>
#include <limits>
#include <iomanip>
#include <functional>
#include <cassert>
using namespace std;

using ll=long long;
template<class T> using V = vector<T>;
template<class T, class U> using P = pair<T, U>;
using vll = V<ll>;
using vvll = V<vll>;
#define ALL(v) v.begin(),v.end()
template < class T > inline bool chmax(T& a, T b) {if (a < b) { a=b; return true; } return false; }
template < class T > inline bool chmin(T& a, T b) {if (a > b) { a=b; return true; } return false; }
#define DEBUG_VLL(vec) for(int sz=0;sz<int(vec.size());sz++) std::cerr<<vec[sz]<<(sz==vec.size()-1?'\n':' ');

const long long MOD = 1000000007;
const long long HIGHINF = (long long)1e18;
const int INF = (int)1e9;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    string s, t; cin >> s >> t;
    V< V<int> > lcs(int(s.size()) + 1, V<int>(int(t.size()) + 1, 0));
    for (int i = 0; i < int(s.size()); i++) {
        for (int j = 0; j < int(t.size()); j++) {
            if (s[i] == t[j]) lcs[i + 1][j + 1] = lcs[i][j] + 1;
            else lcs[i + 1][j + 1] = max(lcs[i + 1][j], lcs[i][j + 1]);
        }
    }

    int i = s.size(), j = t.size();
    string ans;
    while (i > 0 && j > 0) {
        if (s[i - 1] == t[j - 1]) {
            ans.push_back(s[i - 1]);
            i--, j--;
        } else {
            if (lcs[i - 1][j] == lcs[i][j]) i--;
            else j--;
        }
    }
    reverse(ALL(ans));
    cout << ans << '\n';
    return 0;
}
