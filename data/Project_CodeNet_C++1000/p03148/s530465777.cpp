#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <algorithm>
#include <numeric>
#include <utility>
#include <cmath>
#include <tuple>
#include <queue>
#include <bitset>
#include <set>
#include <map>
#include <list>

using namespace std;


void solve(long long N, long long K, std::vector<long long> t, std::vector<long long> d){
  vector<vector<long long>> V(N, vector<long long>());
  vector<long long> top;
  vector<long long> rest;
  for (int i = 0; i < N; ++i) {
    V[t[i]-1].push_back(d[i]);
  }
  for (int i = 0; i < N; ++i) {
    if (V[i].size() > 0) {
      sort(V[i].begin(), V[i].end());
      top.push_back(V[i].back());
      for (int j = 0; j < V[i].size()-1; ++j) {
        rest.push_back(V[i][j]);
      }
    }
  }
  sort(top.begin(), top.end());
  sort(rest.begin(), rest.end());
  vector<long long> cumtop(top.size()+1, 0LL);
  vector<long long> cumrest(rest.size()+1, 0LL);
  for (int i = 0; i < top.size(); ++i) {
    cumtop[i+1] = cumtop[i] + top[i];
  }
  for (int i = 0; i < rest.size(); ++i) {
    cumrest[i+1] = cumrest[i] + rest[i];
  }
  long long ret = 0;
  long long max_t = static_cast<long long>(top.size());
  long long max_r = static_cast<long long>(rest.size());
  long long tmp;
  for (long long i = 0; i <= min(max_t, K); ++i) {
    tmp = i*i;
    tmp += cumtop.back() - cumtop[max_t-i];
    if (max_r-(K-i) < 0) continue;
    tmp += cumrest.back() - cumrest[max_r-(K-i)];
    ret = max(ret, tmp);
  }
  std::cout << ret << std::endl;
}

int main(){
  long long N;
  scanf("%lld",&N);
  long long K;
  scanf("%lld",&K);
  std::vector<long long> t(N);
  std::vector<long long> d(N);
  for(int i = 0 ; i < N ; i++){
    scanf("%lld",&t[i]);
    scanf("%lld",&d[i]);
  }
  solve(N, K, std::move(t), std::move(d));
  return 0;
}
