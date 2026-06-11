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
#include <utility>


int parent[100005];
int main(){
  int N, M;
  scanf("%d", &N);
  scanf("%d", &M);
  std::vector<int > A(N+M-1), B(N+M-1);
  std::vector<int > in[100005], out[100005], in2[100005];
  for (int i=0; i<N+M-1; i++){
    scanf("%d", &A[i]);
    scanf("%d", &B[i]);
    A[i]--;
    B[i]--;
    out[A[i]].push_back(B[i]);
    in[B[i]].push_back(A[i]);
    in2[B[i]].push_back(A[i]);
  }
  int root;
  for (int i=0; i<N; i++){
    if (in[i].size()==0){
      root=i;
      break;
    }
  }
  std::vector<int> order;
  order.push_back(root);
  std::queue<int> queue;
  queue.push(root);
  while(queue.size()>0){
    int v = queue.front();
    queue.pop();
    for (int vv : out[v]){
      in[vv].erase(std::find(in[vv].begin(), in[vv].end(), v));
      if (in[vv].size()==0){
	order.push_back(vv);
	queue.push(vv);
      }
    }
  }
  std::reverse(order.begin(), order.end());
  int num[100005], ans[100005];
  int counter=0;
  for (int p : order){
    num[p]=counter;
    //printf("num[%d]=%d\n", p, counter);
    counter++;
  }
  for (int i=0; i<order.size(); i++){
    int v = order[i];
    int nummin=100005;
    int minindex=-2;
    if (i==order.size()-1){
      ans[v]=0;
    } else {
      for (int p : in2[v]){
	if (num[p]<nummin){
	  nummin=num[p];
	  minindex = p;
	}
      }
      ans[v]=minindex+1;
      //printf("ans[%d]=%d\n", v, ans[v]);
    }
  }
  for (int i=0; i<N; i++){
    printf("%d\n", ans[i]);
  }
  
  return 0;
  
}
 