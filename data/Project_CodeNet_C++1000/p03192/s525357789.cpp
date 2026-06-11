#include <iostream>
using namespace std;

int main(void){
  int ans = 0;
  
  for (int i=0; i<4; i++){
    char c; cin >> c;
    ans += c=='2';
  }
  cout << ans << endl;
  return 0;
}