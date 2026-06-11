#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pl = pair<ll,ll>;
template <class T> ostream &operator<<(ostream &os, vector<T> &v) {
  for (auto i = v.begin(); i != v.end(); i++) {
    os << *i << " ";
  }
  return os;
}
const long long MOD = 1000000007;
vector<int> places[210000];
long long dp[210000];
void add(long long &a, long long b) { a += b; if (a >= MOD) a -= MOD; }
int main() {
    // 入力
    int N; cin >> N;
    vector<int> c(N);
    for (int i = 0; i < N; ++i) cin >> c[i];
    // places[i] := (c[j] = i となるような j の集まり)
    for (int i = 0; i < 210000; ++i) places[i].clear();
    for (int i = 0; i < N; ++i) places[c[i]].push_back(i);
    // DP
    dp[0] = 1;
    for (int i = 1; i <= N; ++i) {
        // 特に操作しない場合
        add(dp[i], dp[i-1]);
        // 操作する場合
        int color = c[i-1];
        int it = lower_bound(places[color].begin(), places[color].end(), i-1)
            - places[color].begin(); // c[i] が color 色の何番目の要素か
        if (it > 0) {
            int j = places[color][it - 1]; // c[j] = c[i] となる j
            if ((i-1) - j > 1) add(dp[i], dp[j+1]);
        }
    }
    std::cout << dp[N] << std::endl;
}
