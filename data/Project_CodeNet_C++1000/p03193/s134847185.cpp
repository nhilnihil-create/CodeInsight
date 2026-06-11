#include <iostream>
using namespace std;

int main(void){
  int n, ans = 0;
  long long w,h;
  
  cin >> n >> w >> h;
  for (int i=0; i<n; i++){
    long long a, b; cin >> a >> b;
    ans += a>=w&&b>=h;
  }
  cout << ans << endl;
  return 0;
}