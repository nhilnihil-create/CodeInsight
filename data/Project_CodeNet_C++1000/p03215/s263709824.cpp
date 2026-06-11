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
long long a[1000];
long long cum_sum[1001];
int main(){
  int N;
  int K;
  cin >> N >> K;
  for(int i = 0; i < N; i++){
      cin >> a[i];
  }
  
  cum_sum[0] = 0;
  for(int i = 0; i < N; i++){
      cum_sum[i + 1] = cum_sum[i] + a[i];
  }
  vector <long long> sums;
  for(int i = 0; i < N; i++){
      for(int j = i + 1; j < N + 1; j++){
          sums.push_back(cum_sum[j] - cum_sum[i]);
      }
  }
  
  /*
  for(int i = 0; i < sums.size(); i++){
      cout << sums[i] << " ";
  }
  cout << endl;
  cout << sums.size() << endl;
  */
  map <int, int> bit_counts;
  for(int i = 0; i < 45; i++){
      bit_counts[i] = 0;
      for(int j = 0; j < sums.size(); j++){
          if(((sums[j] >> i) & (long long) 1) == (long long) 1){
              bit_counts[i] ++;
          }
      }
  }
  
  long long ans = 0;
  for(int i = 44; i >= 0; i--){
      if(bit_counts[i] >= K){
          ans += ((long long) 1 << i);
          bit_counts.clear();
          vector <long long> new_sums;
          for(int j = 0; j < sums.size(); j++){
              if(((sums[j] >> i) & 1) == 1){
                  new_sums.push_back(sums[j]);
              }
          }
          sums = new_sums;
          for(int j = 0; j < 45; j++){
            bit_counts[j] = 0;
            for(int k = 0; k < sums.size(); k++){
                if(((sums[k] >> j) & (long long) 1) == (long long) 1){
                    bit_counts[j] ++;
                }
            }
          }
          
      }
  }
  cout << ans << endl;
  return 0;
}