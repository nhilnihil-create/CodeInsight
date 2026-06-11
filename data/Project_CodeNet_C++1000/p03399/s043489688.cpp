#include <iostream>
using namespace std;
int main(void){
  int a, b, c, d;
  cin>>a>>b>>c>>d;
  int ans = min(a, b)+min(c,d);
  cout<<ans<<endl;
  return 0;
}
