#include <iostream>
#include <cmath>

using namespace std;
int main(){
  int x;
  cin >> x;
  if(x == 1) {
    cout << 1 << endl;
    return 0;
  }

  int ret = 1;
  for(int i = 2; i < 100; i++) {
    for(int j = 2; j < 100; j++) {
      if((int)pow(i, j) <= x) {
        ret = max(ret, (int)pow(i, j));
      } else {
        break;
      }
    }
  }

  cout << ret << endl;
  return 0;
} 
