#include <cstdio>
#include <vector>
#include <algorithm>

int n;
int W[1000], S[1000], V[1000];


std::vector<std::pair<int, long long int> > dp0, dp1, dp2;

int main(){
  scanf("%d", &n);
  for(int i = 0; i < n; i++) scanf("%d%d%d", W+i, S+i, V+i);
  std::vector<std::pair<int, int> > v;
  for(int i = 0; i < n; i++){
    v.emplace_back(S[i] + W[i], i);
  }
  std::sort(v.begin(), v.end());

  std::vector<long long int> sum(n+1);
  for(int i = n-1; i >= 0; i--) sum[i] = sum[i+1] + V[v[i].second];

  dp0.emplace_back(0, 0);
  for(int i = 0; i < n; i++){
    int j = v[i].second;
    for(const auto &x: dp0){
      if(x.first > S[j]) break;
      dp1.emplace_back(x.first + W[j], x.second + V[j]);
    }
    auto i0 = dp0.begin();
    auto i1 = dp1.begin();
    long long int best = std::max(dp0.back().second, dp1.empty() ? 0 : dp1.back().second);
    while(i0 != dp0.end() && i0->second + sum[i+1] < best) ++i0;
    while(i1 != dp1.end() && i1->second + sum[i+1] < best) ++i1;

    while(i0 != dp0.end() && i1 != dp1.end()){
      if(i0->first <= i1->first && i0->second >= i1->second) ++i1;
      else if(i0->first >= i1->first && i0->second <= i1->second) ++i0;
      else if(i0->first <= i1->first) dp2.push_back(*i0), ++i0;
      else dp2.push_back(*i1), ++i1;
    }
    dp2.insert(dp2.end(), i0, dp0.end());
    dp2.insert(dp2.end(), i1, dp1.end());
    dp1.clear();
    dp0.swap(dp2);
    dp2.clear();
//    for(const auto &x: dp0) printf("(%d %lld) ", x.first, x.second);
//    puts("");
  }
  printf("%lld\n", dp0.back().second);
  return 0;
}
