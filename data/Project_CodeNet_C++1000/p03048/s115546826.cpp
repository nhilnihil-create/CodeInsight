#include <iostream>
using namespace std;

int main(void){
  int r, g, b, n;
  int ans;
  
  cin >> r >> g >> b >> n;
  ans = 0;
  for (int i=0; i*r<=n; i++){
    for (int j=0; i*r+j*g<=n; j++){
      if ((n-i*r-j*g)%b==0){
//        cout << i << " " << j << " " << (n-i*r-j*g) << endl;
        ans++;
      }
    }
  }
  cout << ans << endl;
  return 0;
}
