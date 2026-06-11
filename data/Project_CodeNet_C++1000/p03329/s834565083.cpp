#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;

using i64 = int64_t;
i64 INF = 1ll << 60;

void chmin(i64 &a, i64 b){
  if(a > b)
    a = b;
}

int main(){
  int n;
  cin >> n;
  vector<int> ex6(8), ex9(8);
  ex6[0] = 1;
  ex9[0] = 1;
  for(int i = 1; i < 8; i++){
    ex6[i] = 6*ex6[i-1];
    ex9[i] = 9*ex9[i-1];
  }
  
  vector<i64> sum(100010, INF);
  sum[0] = 0;
  
  for(int i = 0; i <= n; i++){
    chmin(sum[i+1], sum[i]+1);
    for(int j = 1; j < 8; j++){
      if(i+ex6[j] <= n)
        chmin(sum[i+ex6[j]], sum[i]+1);
      if(i+ex9[j] <= n)
        chmin(sum[i+ex9[j]], sum[i]+1);
    }
  }
  
  cout << sum[n] << endl;
  
  return 0;
  
}