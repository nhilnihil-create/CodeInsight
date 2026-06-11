#include<iostream>
#include<algorithm>
#include<queue>
#include<map>
#include<set>
#include<string>
#include<cstdlib>
template<typename T>
void fin(T const& t){ std::cout << t << std::endl; exit(0); }

int main() {
  std::cin.tie(0); std::ios::sync_with_stdio(false);
  int N, M; std::cin >> N >> M;
  std::string s; std::cin >> s;
  std::vector<std::vector<int>> G(N);
  std::vector<int> dA(N,0), dB(N,0);
  std::set<std::pair<int,int>> ps;
  for(int i = 0; i < M; ++i) {
    int a, b; std::cin >> a >> b; --a; --b;
    if(a > b) std::swap(a,b);
    if(ps.count(std::make_pair(a,b))) continue;
    ps.insert({a,b});
    G[a].push_back(b);
    G[b].push_back(a);
    if(s[a]=='A') ++dA[b]; else ++dB[b];
    if(a < b) {
      if(s[b]=='A') ++dA[a]; else ++dB[a];
    }
  }
  std::queue<int> q;
  for(int i = 0; i < N; ++i) if(dA[i] == 0 || dB[i] == 0) q.push(i);
  while(!q.empty()) {
    int i = q.front(); q.pop();
    if(s[i] == ' ') continue;
    auto& deg = (s[i] == 'A'? dA: dB);
    s[i] = ' ';
    for(int j: G[i]) if(--deg[j] == 0) q.push(j);
  }
  for(char c: s) if(c!=' ') fin("Yes");
  fin("No");
  return 0;
}
