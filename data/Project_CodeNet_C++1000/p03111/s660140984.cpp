#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define all(x) (x).begin(),(x).end()
using ll = long long;
string char_to_string(char val) {
  return string(1, val);
}
int char_to_int(char val) {
  return val - '0';
}
template<class T> inline bool chmin(T& a, T b) {
  if (a > b) {
    a = b;
    return true;
  }
  return false;
}
template<class T> inline bool chmax(T& a, T b) {
  if (a < b) {
    a = b;
    return true;
  }
  return false;
}
int vector_finder(std::vector<ll> vec, int number) {
  auto itr = std::find(vec.begin(), vec.end(), number);
  size_t index = std::distance( vec.begin(), itr );
  if (index != vec.size()) { // 発見できたとき
    return 1;
  }
  else { // 発見できなかったとき
    return 0;
  }
}
int ans = 1000000007;
int N, A, B, C; 
vector<int> l; 
void dfs(int mp, int i, int a, int b, int c) {
  if(i == N) {
    if(a == 0 || b == 0 || c == 0) return;
    int tmp = abs(A - a) + abs(B - b) + abs(C - c) + mp;
    if(ans > tmp) ans = tmp;
    return;
  }
  dfs(mp, i + 1, a, b, c);
  if(a == 0) dfs(mp, i + 1, a + l[i], b, c);
  else dfs(mp + 10, i + 1, a + l[i], b, c);
  if(b == 0) dfs(mp, i + 1, a, b + l[i], c);
  else dfs(mp + 10, i + 1, a, b + l[i], c);
  if(c == 0) dfs(mp, i + 1, a, b, c + l[i]);
  else dfs(mp + 10, i + 1, a, b , c + l[i]);
}
int main() {
  cin >> N;
  cin >> A >> B >> C;
  l.resize(N); REP(i, N) cin >> l[i];
  dfs(0, 0, 0, 0, 0);
  cout << ans << endl;
}