#include<iostream>
#include<vector>
#include<algorithm>
#include<cstdlib>
template<typename T>
void fin(T const& t){ std::cout << t << std::endl; exit(0); }

int const INF = 1e9+5;

int main() {
  std::cin.tie(0); std::ios::sync_with_stdio(false);
  int N, K; std::cin >> N >> K;
  std::vector<int> V(N), S(N+1, 0);
  for(int i = 0; i < N; ++i) std::cin >> V[i];
  for(int i = 0; i < N; ++i) S[i+1] = S[i] + V[i];
  int ans = 0;
  auto calc = [&](int nt, int np)->int {
    int sum = -INF, q = N-nt;
    int res = 0;
    for(int p = 0; p <= nt; ++p) {
      int cur = S[N] - S[p+q] + S[p];
      std::vector<int> dis(V.begin(), V.begin()+p);
      for(int i = p+q; i < N; ++i) dis.push_back(V[i]);
      std::sort(dis.begin(), dis.end());
      int cnt = 0;
      for(int v: dis) {
        if(v >= 0) break;
        if(++cnt > np) break;
        cur -= v;
      }
      res = std::max(res, cur);
    }
    return res;
  };
  for(int i = 0; i <= std::min(N, K); ++i) {
    // take i jems, then put <=j jems back
    int j = std::min(K-i, i);
    ans = std::max(ans, calc(i, j));
  }
  fin(ans);
  return 0;
}
