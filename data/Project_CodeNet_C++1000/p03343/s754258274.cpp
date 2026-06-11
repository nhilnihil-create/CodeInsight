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
#include <numeric>
#include <iomanip>
#include <cmath>
#include <cstring>
using namespace std;
long long A[2000];
vector <long long> divided_A[2000];
int main(){
  int N;
  int K;
  int Q;
  cin >> N >> K >> Q;
  for(int i = 0; i < N; i++){
    cin >> A[i];
  }

  long long ans = LLONG_MAX;
  for(int i = 0; i < N; i++){
    long long cur_min = A[i];
    for(int j = 0; j < N; j++){
      divided_A[j].clear();
    }
    int div_no = 0;
    bool in_div = false;
    for(int j = 0; j < N; j++){
      if(A[j] >= cur_min){
        if(in_div){
          divided_A[div_no - 1].push_back(A[j]);
        } else {
          in_div = true;
          div_no ++;
          divided_A[div_no - 1].push_back(A[j]);
        }
      } else {
        if(in_div){
          in_div = false;
        }
      }
    }

    vector <long long> candidates;
    for(int j = 0; j < div_no; j++){
      if(divided_A[j].size() >= K){
        sort(divided_A[j].begin(), divided_A[j].end());
        for(int k = 0; k < divided_A[j].size() - (K - 1); k++){
          candidates.push_back(divided_A[j][k]);
        }
      }
    }
    //for(int j = 0; j < candidates.size(); j++){
    //  cout << candidates[j] << " ";
    //}
    //cout << endl;
    if(candidates.size() >= Q){
      sort(candidates.begin(), candidates.end());
      ans = min(ans, candidates[Q - 1] - candidates[0]);
    }
  }
  cout << ans << endl;
  return 0;
}
