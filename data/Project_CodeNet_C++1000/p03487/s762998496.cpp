#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <utility>
#include <tuple>
#include <queue>
#include <deque>
#include <map>
#include <set>
#include <cmath>
#include <iomanip>
#include <functional>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define ALL(x) (x).begin(), (x).end()
#define SZ(x) (int)(x).size()
using namespace std;
using ll = long long;
constexpr int inf = 1000000000;
constexpr ll INF = 1000000000000000000;
template <typename T> bool chmin(T &x, const T &y) {if (x < y) {x = y; return true;} return false;}
template <typename T> bool chmax(T &x, const T &y) {if (x > y) {x = y; return true;} return false;}

int main() {
    int N;
    cin >> N;
    vector<int> A(N);
    rep(i, N) cin >> A[i];
    
    map<int, int> cnt;
    rep(i, N) ++cnt[A[i]];
    int ans = 0;
    for (auto p : cnt) {
        if (p.second < p.first) ans += p.second;
        if (p.first < p.second) ans += (p.second - p.first);
    }
    cout << ans << "\n";
    return 0;
}
