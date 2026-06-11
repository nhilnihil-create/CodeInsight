#include <iostream>
#include <string>
#include <vector>
#include <deque>
#include <queue>
#include <algorithm>
#include <set>
#include <map>
#include <bitset>
#define vv(a, b, c, d) vector<vector<d> >(a, vector<d>(b, c))
#define vvi std::vector<std::vector<int> >
#define vvl std::vector<std::vector<ll> >
#define MODs 1000000007;
typedef long long int ll;
using namespace std;

vvi G = vv(200001, 0, 0, int);
vvi p = vv(200001, 2, 0, int);
std::vector<int> c(200001);

int main(int argc, char const *argv[]) {
  int N, M, a, b;
  std::cin >> N >> M;
  string S;
  std::cin >> S;
  for(int i=0;i<N;i++) c[i+1] = (S[i]=='A'?1:0);
  for(int i=0;i<M;i++){
    std::cin >> a >> b;
    G[a].push_back(b);
    G[b].push_back(a);
    (c[b]==1?p[a][0]:p[a][1]) += 1;
    (c[a]==1?p[b][0]:p[b][1]) += 1;
  }
  //for(int i=1;i<=N;i++) std::cout << i << " " <<p[i][0] << " " << p[i][1] << '\n';
  deque<int> q;
  for(int i=1;i<=N;i++) if(p[i][0]==0||p[i][1]==0) q.push_back(i);
  set<int> num;
  for(int i=1;i<=N;i++) num.insert(i);

  while(!q.empty()){
    int x = q.front();
    q.pop_front();
    if(num.find(x)==num.end()) continue;
    num.erase(x);
    //std::cout << x << '\n';
    for(int i=0;i<G[x].size();i++){
      if(num.find(G[x][i])==num.end()) continue;
      (c[x]==1?p[G[x][i]][0]:p[G[x][i]][1])-=1;
      if(p[G[x][i]][0]==0||p[G[x][i]][1]==0) q.push_back(G[x][i]);
    }
    p[x][0] = p[x][1] = 0;
  }
  //for(int i=1;i<=N;i++) std::cout << i << " " << p[i][0] << " " << p[i][1] << '\n';
  //for(auto itr = num.begin(); itr!=num.end();itr++) std::cout << *itr << " ";
  std::cout << (num.empty()?"No":"Yes") << '\n';
  return 0;
}
