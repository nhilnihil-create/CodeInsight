#include <iostream>
#include <algorithm>
using namespace std;

int main(){
  int A, B;
  cin >> A >> B;
  
  int ans;
  ans = A > B?A--:B--;
  ans += max(A, B);
  
  cout << ans << endl;
  
  return 0;
}