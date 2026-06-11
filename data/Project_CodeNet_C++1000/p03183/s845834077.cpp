
#include <cstdio>
#include <vector>
#include <algorithm>

int n;
int W[1000], S[1000], V[1000];


long long int dp[20001];

int main(){
  scanf("%d", &n);
  for(int i = 0; i < n; i++) scanf("%d%d%d", W+i, S+i, V+i);
  std::vector<std::pair<int, int> > v;
  for(int i = 0; i < n; i++){
    v.emplace_back(S[i] + W[i], i);
  }
  std::sort(v.begin(), v.end());
  for(int i = 0; i < n; i++){
    int j = v[i].second;
    for(int k = S[j] + W[j]; k >= W[j]; k--){
      dp[k] = std::max(dp[k], dp[k - W[j]] + V[j]);
    }
  }
  long long int ans = 0;
  for(int i = 0; i <= 20000; i++) ans = std::max(ans, dp[i]);
  printf("%lld\n", ans);
  return 0;
}
