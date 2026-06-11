#include <iostream>
#include <vector>

/*
 L 1e6
 */

class edge{
public:
  int from, to, cost;
  
  edge(int f, int t, int c){
    from = f;
    to = t;
    cost = c;
  }
};

int main(){
  
  int L, N, M;
  int tmp, tmp_L;
  
  // read L
  scanf("%d", &L);
  
  // calculate N : 2^{N-1} <= L < 2^(N)
  N = 0;
  tmp = L;
  while(tmp > 0){
    tmp /= 2;
    N++;
  }
  
  // solve problem
  std::vector<class edge> graph;
  M = 0;
  // set initial edges
  for(int i = 1; i < N; i++){
    graph.push_back(edge(i, i+1, 0));
    graph.push_back(edge(i, i+1, (1 << N-1-i)));
    M += 2;
  }
  
  // push additional edges
  tmp = L;
  for(int i = 0; i < N-1; i++){
    if((tmp & (1 << i)) != 0){
      tmp -= (1 << i);
      graph.push_back(edge(1, N-i, tmp));
      M++;
    }
  }
  
  // print answer
  std::cout << N << " " << M << std::endl;
  for(int i = 0; i < M; i++){
    std::cout << graph[i].from << " ";
    std::cout << graph[i].to << " ";
    std::cout << graph[i].cost << std::endl;
  }
  
  return 0;
}
