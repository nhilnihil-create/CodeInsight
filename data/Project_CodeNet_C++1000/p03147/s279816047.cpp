#include <iostream>

using namespace std;

int main(){
  int n; cin >> n;
  int h[n];
  for(int i=0; i<n; ++i) cin >> h[i];
  
  int res = 0;
  bool flag = true;
  while(flag){
    flag = false;
    for(int i=0; i<n; ++i){
      if(h[i] != 0){
        --h[i];
        flag = true;
        if(i+1 == n || h[i+1] == 0) ++res;
      }
    }
  }
  
  cout << res << endl;
  return 0;
}