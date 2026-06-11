#define _USE_MATH_DEFINES
#include <iostream>
#include <string>
#include <utility>
#include <stack>
#include <vector>
#include <queue>
#include <algorithm>
#include <map>
#include <climits>
#include <set>
#include <cmath>
#include <numeric>
#include <iomanip>

using namespace std;
vector <int> edges[100000];
int group[100000];
bool dfs(int cur, int cur_mod){
  group[cur] = cur_mod;
  for(int i = 0; i < edges[cur].size(); i++){
    int next = edges[cur][i];
    if(group[next] == cur_mod){
      return false;
    } else if(group[next] < 0){
      if(!dfs(next, (cur_mod + 1) % 2)){
        return false;
      }
    }
  }
  return true;
}

int main(void){
  long long N;
  long long M;
  cin >> N >> M;
  for(int i = 0; i < M; i++){
    int A;
    int B;
    cin >> A >> B;
    edges[A - 1].push_back(B - 1);
    edges[B - 1].push_back(A - 1);
  }

  for(int i = 0; i < N; i++){
    group[i] = -1;
  }

  if(dfs(0, 0)){
    long long group_0_count = 0;
    for(int i = 0; i < N; i++){
      if(group[i] == 0){
        group_0_count ++;
      }
    }
    cout << group_0_count * (N - group_0_count) - M << endl;
  } else {
    cout << (N * (N - 1) - (long long) 2 * M) / (long long) 2;
  }
  return 0;
}
