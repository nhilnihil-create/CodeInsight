#include<iostream>
#include<vector>
#include<map>
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
    std::vector<int> v(V.begin(), V.begin()+nt);
    std::sort(v.begin(), v.end());
    int st = S[nt], sd = 0, cnt = 0;
    std::map<int,int> dis, keep;
    for(int vv: v) {
      if(vv >= 0) break;
      if(++cnt > np) ++keep[vv];
      else {
        sd += vv;
        ++dis[vv];
      }
    }
    if(cnt > np) cnt = np;
    int res = st - sd;
    for(int i = 0; i < nt; ++i) {
      // remove V[nt-1-i]
      int tgt = V[nt-1-i];
      st -= tgt;
      if(keep.count(tgt) > 0) { // if in keep
        if(--keep[tgt] == 0) keep.erase(tgt);
      } else if(dis.count(tgt) > 0) { // if only in dis
        sd -= tgt;
        if(--dis[tgt] == 0) dis.erase(tgt);
        if(--cnt < np && keep.size() > 0) { // move one from keep
          ++cnt;
          tgt = keep.begin()->first;
          sd += tgt;
          ++dis[tgt];
          if(--keep[tgt] == 0) keep.erase(tgt); 
        }
      }
      // add V[N-1-i] 
      tgt = V[N-1-i];
      st += tgt;
      if(tgt < 0) {
        sd += tgt;
        ++dis[tgt];
        if(++cnt > np) {
          --cnt;
          // move one to keep
          tgt = dis.rbegin()->first;
          sd -= tgt;
          if(--dis[tgt] == 0) dis.erase(tgt);
          ++keep[tgt];
        }
      }
      res = std::max(res, st - sd);
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
