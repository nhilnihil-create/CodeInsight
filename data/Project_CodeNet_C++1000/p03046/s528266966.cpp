#include<iostream>
#include<vector>
#include<algorithm>
#include<cstdlib>
template<typename T>
void fin(T const& t){ std::cout << t << std::endl; exit(0); }

int main() {
  std::cin.tie(0); std::ios::sync_with_stdio(false);
  int M, K; std::cin >> M >> K;
  if(M == 0) {
    if(K > 0) fin(-1);
    fin("0 0");
  }
  if(M == 1) {
    if(K > 0) fin(-1);
    fin("0 0 1 1");
  }
  if(K >= (1<<M)) fin(-1);
  char sp = ' ';
  if(K == 0) {
    int i = 0;
    for(; i < (1<<M)-1; ++i) std::cout << i << sp << i << sp;
    std::cout << i << sp;
    fin(i);
  }
  std::vector<int> ans;
  std::vector<bool> used(1<<M+1, false);
  for(int i = 0; i < (1<<M); ++i) if(!used[i]){
    ans.push_back(i);
    int j = i^K;
    used[i] = used[j] = true;
  }
  for(int i = 0; i < ans.size(); i += 2) {
    int a = ans[i], b = ans[i+1], c = a^K, d = b^K;
    std::cout << a << sp << c << sp << b << sp << d << sp
              << c << sp << a << sp << d << sp << b;
    if(i+2 == ans.size()) sp = '\n';
    std::cout << sp;
  }
  return 0;
}
