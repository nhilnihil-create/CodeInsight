#include <iostream>
using namespace std;
int main(){
  int A[3],ma = 0,ans = 0;
  for(auto& i: A){ cin >> i ; ma = max(ma,i); ans += i;}
  ans += ma*9;
  cout << ans << endl;
}
