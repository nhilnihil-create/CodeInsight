#include <algorithm>
#include <deque>
#include <iostream>
#include <map>
#include <math.h>
#include <queue>
#include <set>
#include <stack>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unordered_map>
#include <vector>

int main() {
  int N;
  scanf("%d", &N);
  std::queue<std::pair<int, int > > queue;
  int target = (N%2==0)?N+1:N;
  for (int i=1; i<=N; i++){
    for (int j=i+1; j<=N; j++){
      if (i==j) continue;
      if (i+j==target) continue;
      queue.push(std::make_pair(i, j));
    }
  }
  std::cout << queue.size() << std::endl;
  while(queue.size()>0){
    auto top = queue.front();
    queue.pop();
    std::cout << top.first << " " << top.second << std::endl; 
  }
  return 0;
}
