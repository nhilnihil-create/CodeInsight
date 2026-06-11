#include <iostream>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <queue>
#include <stack>
#include <vector>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <set>
#include <deque>

std::vector<int > edge[100004];
std::vector<int > c(100004);
std::vector<int > ans(100004);
std::vector<bool> visited;
std::priority_queue<int > queue;

void dfs(int n, int p){
  for (int i=0; i<edge[n].size(); i++){
    int tgt=edge[n][i];
    if (visited[tgt]) continue;
    //std::cout << "tgt=" << tgt << std::endl;
    visited[tgt]=true;
    int highest=queue.top();
    //std::cout << "highest in dfs=" << highest << std::endl;
    queue.pop();
    ans[tgt]=highest;
    dfs(tgt, n);
  }
  return;
}

int main(){
  int N;
  scanf("%d", &N);
  int a, b;
  visited=std::vector<bool>(100004, false);
  for (int i=0; i<N-1; i++){
    scanf("%d", &a);
    scanf("%d", &b);
    a--;
    b--;
    edge[a].push_back(b);
    edge[b].push_back(a);
  }
  long long sum=0;
  for (int i=0; i<N; i++){
    scanf("%d", &c[i]);
    sum+=c[i];
    queue.push(c[i]);
  }
  //std::sort(c.begin(), c.end(), std::greater<int >());
  int highest=queue.top();
  queue.pop();
  //std::cout << "highest=" << highest << std::endl;
  std::cout << sum-highest << std::endl;
  ans[0]=highest;
  visited[0]=true;
  dfs(0, -1);
  for (int i=0; i<N; i++){
    printf("%d%c",ans[i],(i==N-1)?'\n':' ');
  }
  return 0;
}