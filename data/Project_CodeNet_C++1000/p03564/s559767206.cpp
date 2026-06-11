#include <bits/stdc++.h>
using namespace std;

template<class T> inline bool chkMin(T& a, T b){
  if(a > b){
    a = b;
    return true;
  }
  return false;
}

int main() {
  int num,k;
  int Min = 1;
  int tmp = 1;
  cin >> num >> k;
  
  for(int i = 0; i < num; i++){
    tmp = Min;
    Min = min(tmp * 2, tmp + k);
  }
  
  cout << Min;
}
