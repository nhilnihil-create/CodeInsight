#include <iostream>
using namespace std;




int main() {
  int v[5];
  for (int i = 0; i < 5; i++) {
    cin >> v[i];
  }

  int minIdx = -1;
  int minRest = 10;
  for (int i = 0; i < 5; i++) {
    if(v[i]%10!=0 && v[i]%10<minRest) {
      minIdx = i;
      minRest = v[i]%10;
    }
  }
  
  int ans = 0;
  for (int i = 0; i < 5; i++) {
    if(i==minIdx) {
      ans += v[i];
      continue;
    }
    ans += ((v[i]+10-1)/10)*10;
  }
  cout << ans << endl;

  return 0;
}
