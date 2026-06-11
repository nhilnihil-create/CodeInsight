#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>
#include <map>
#include <iomanip>
#include <stdlib.h>
#include <queue>

using namespace std;

const int nmax = 1e9 + 7;
const long long INF = 1e18;
const double PI = 2 * asin(1);
typedef long long ll;


int main(){
  
  int num[10] = {0,2,5,5,4,5,6,3,7,6};
  vector < pair<int, int> > candidate;
  int N, M; cin >> N >> M;
  for (int i = 0; i < M; i++){
    int A; cin >> A;
    candidate.push_back(make_pair(A, num[A]));
  }
  sort(candidate.begin(), candidate.end(), greater< pair<int, int> >());
  
  map <int, int> DP;
  for (int i = 0; i < candidate.size(); i++){
    DP[candidate[i].second] = 1;
  }
  
  for (int i = 2; i < N + 1; i++){
    if (DP[i] > 0){
      for (int j = 0; j < candidate.size(); j++){
        int num = candidate[j].second;
        DP[i + num] = max(DP[i + num], DP[i] + 1);
      }
    }
  }
  
  int dig = DP[N], sum = N;
  while (dig > 0){    
    for (int i = 0; i < candidate.size(); i++){
      int now = candidate[i].second;
      if (DP[sum - now] + 1 == DP[sum] && DP[sum] > 1){
        cout << candidate[i].first;
        sum -= now;
        break;
      }else if(DP[sum] == 1 && sum == now){
        cout << candidate[i].first;
        sum -= now;
        break;
      }
    }
    dig--;
  }
  cout << endl;

  return 0;
}
