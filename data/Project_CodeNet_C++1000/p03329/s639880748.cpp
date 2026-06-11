#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;

int dfs(int rest, int count) {
  if(rest==0) return count;
  if(rest<6) return dfs(rest-1,count+1);

  int ret=INF;
  int numFor6=0;
  while(rest>=pow(6,numFor6)){
    numFor6++;
  }
  ret = min(ret, dfs(rest-pow(6,numFor6-1),count+1));

  int numFor9=0;
  while(rest>=pow(9,numFor9)){
    numFor9++;
  }
  ret = min(ret, dfs(rest-pow(9,numFor9-1),count+1));

  return ret;
}


int main() {
  int N;
  cin >> N;

  cout << dfs(N, 0) << endl;

  return 0;
}