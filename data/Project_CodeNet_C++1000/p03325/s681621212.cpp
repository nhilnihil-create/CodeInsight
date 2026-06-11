#include <iostream>

using namespace std;

int main() {

  int n, ans = 0, good = 0;
  cin >> n;
  for(int i = 1;i <= n;i++){
    cin >> good;
    while(good % 2 == 0){
      ans++;
      good /= 2;
    }
  }
  cout << ans;
  return 0;
}
