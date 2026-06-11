#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<cstdlib>
template<typename T>
void fin(T const& t){ std::cout << t << std::endl; exit(0); }

int main() {
  std::cin.tie(0); std::ios::sync_with_stdio(false);
  std::string s; std::cin >> s;
  int N = s.size();
  std::vector<int> v(N+1);
  v[0] = 0;
  for(int i = 0; i < N; ++i) v[i+1] = v[i] ^ (1<<s[i]-'a');
  std::vector<int> dp(1<<26, N+1);
  int ans = 0;
  dp[0] = 0;
  for(int i = 0; i < N; ++i) {
    ans = dp[v[i+1]]+1;
    for(int j = 0; j < 26; ++j) {
      ans = std::min(ans, dp[v[i+1]^(1<<j)]+1);
    }
    dp[v[i+1]] = std::min(dp[v[i+1]], ans);
  }
  fin(ans);
  return 0;
}
