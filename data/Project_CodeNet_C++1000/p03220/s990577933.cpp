#include "bits/stdc++.h"
using namespace std;

int main(){
  
  int n, t, a;
  cin >> n >> t >> a;
  
  vector<int>h(n);
  
  int i = 0;
  for(i = 0; i < n; i++){
    cin >> h[i];
  }
  
  double ans = 0;
  int select = 0;
  double tmp;
  double sub;
  for(i = 0; i < n; i++){
    tmp = t - h[i]*0.006;
    sub = a - tmp;
    if(i == 0){
      ans = abs(sub);
      select = 1;
    }
    else{
      if(ans > abs(sub)){
        ans = abs(sub);
        select = i + 1;
      }
    }
  }
  
  cout << select;

  return 0;
}