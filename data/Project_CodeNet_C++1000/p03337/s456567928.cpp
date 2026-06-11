#include <iostream>
using namespace std;

int main(){
  int a,b,c,ans;
  cin >> a >> b >>c;
  ans = max(a+b,a-b);
  ans = max(ans,a*b);
  cout << ans;
}
