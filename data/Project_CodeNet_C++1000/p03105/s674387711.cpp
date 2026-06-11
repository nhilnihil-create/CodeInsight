#include <iostream>
#include <algorithm>
using namespace std;

int main() {
  int A, B, C;
  cin >> A >> B >> C;
  
  int ans = 0;
  while(C>0){
    if ( B - A < 0) break;
    ans++;
    B -= A;
    C--;
  }
  
  cout << ans << endl;
  
  return 0;
}
