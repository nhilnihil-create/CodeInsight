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
    int N, K;
    cin >> N >> K;
    vector<int> A(N);
    rep(i, N) cin >> A[i];
    
    map<int, int> cnt;
    rep(i, N) ++cnt[A[i]];
    vector<int> S;
    for (auto p : cnt) S.push_back(p.second);
    sort(ALL(S));
    int ans = 0;
    rep(i, max(SZ(S) - K, 0)) {
        ans += S[i];
    }
    cout << ans << "\n";
    return 0;
}
