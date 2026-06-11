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
std::queue<int > q;


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
  int highest=queue.top();
  queue.pop();
  std::cout << sum-highest << std::endl;
  ans[0]=highest;
  visited[0]=true;
  q.push(0);
  while(q.size()>0){
    int src=q.front();
    q.pop();
    for (int i=0; i<edge[src].size();i++){
      int tgt=edge[src][i];
      if (visited[tgt]) continue;
      visited[tgt]=true;
      int highest=queue.top();
      queue.pop();
      ans[tgt]=highest;
      q.push(tgt);
    }
  }
  for (int i=0; i<N; i++){
    printf("%d%c",ans[i],(i==N-1)?'\n':' ');
  }
  return 0;
}