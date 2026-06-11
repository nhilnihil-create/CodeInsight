#include <iostream>

using namespace std;

int main() {

  int n, odd = 1, p, ans = 0, old = 0;
  cin >> n;
  for(int i =1;i <= n;i++){
    cin >> p;
    if(old != p){
      ans += odd / 2;
      old = p;
      odd = 1;
    }else{
      odd++;
    }
  }
  ans += odd / 2;
  cout << ans;
  return 0;
}
