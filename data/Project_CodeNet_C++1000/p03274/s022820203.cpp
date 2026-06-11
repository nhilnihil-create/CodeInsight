#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

int main(){
  int N, K;
  cin >> N >> K;
  vector<int> left_x, right_x;
  
  for (int i = 0; i < N; i++){
    int tmp;
    cin >> tmp;
    if(tmp < 0) {
      left_x.insert(left_x.begin(), tmp);
    }else{
      right_x.push_back(tmp);
    }
  }
  int ans = 0;

  if(left_x.empty()){
    ans = abs(right_x[K-1]);
  }else if(right_x.empty()){
    ans = abs(left_x[K-1]);
  }else{
    ans = 300000000;
    for (int i = 0; i < K; i++){
      int p = 0;
      if ((left_x.size() <= K-i-2) || (right_x.size() <= i)) continue;
      
      if (abs(right_x[i]) < abs(left_x[K-i-2])) {
        p = abs(right_x[i]);
      }else{
        p = abs(left_x[K-i-2]);
      }

      int tmp = abs(right_x[i]) + abs(left_x[K-i-2]) + p;
      if (tmp < ans) ans = tmp;      
    }

    if (K <= left_x.size() && ans > abs(left_x[K-1])){
      ans = abs(left_x[K-1]);
    }
    if (K <= right_x.size() && ans > abs(right_x[K-1])){
      ans = abs(right_x[K-1]);
    }
  }
  printf("%d\n",ans);

  
}
