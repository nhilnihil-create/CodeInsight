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

int parent[100005];
int length[100005];

void init(){
  for (int i=0; i<100005; i++){
    parent[i]=i;
    length[i]=1;
  }
  return;
}

int getroot(int n){
  while(parent[n]!=n){
    n=parent[n];
  }
  return n;
}

bool samegroup(int n, int m){
  int nroot=getroot(n);
  int mroot=getroot(m);
  return nroot==mroot;
}

bool unite(int n, int m){
  if (samegroup(n, m)){
    return false;
  } else {
    int nroot=getroot(n);
    int mroot=getroot(m);
    if (length[nroot]==length[mroot]){
      parent[nroot]=mroot;
      length[mroot]++;
    } else if (length[nroot]>length[mroot]){
      parent[mroot]=nroot;
      length[nroot]++;
    } else {
      parent[nroot]=mroot;
      length[mroot]++;
    }
    return true;
  }
}

int main(){
  int N, M;
  scanf("%d", &N);
  scanf("%d", &M);
  std::vector<int > X(M), Y(M), Z(M);
  for (int i=0; i<M; i++){
    scanf("%d", &X[i]);
    scanf("%d", &Y[i]);
    scanf("%d", &Z[i]);
    X[i]--;
    Y[i]--;
  }

  init();
  for (int i=0; i<M; i++){
    unite(X[i], Y[i]);
  }
  std::set<int > leader;
  for (int i=0; i<N; i++){
    leader.insert(getroot(i));
  }
  std::cout << leader.size() << std::endl;
  return 0;
}