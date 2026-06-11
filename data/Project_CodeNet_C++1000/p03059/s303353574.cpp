#include <iostream>

using namespace std;

int main(){
  double a,b,c,d,ans=0;
  cin >> a >> b >> c;
  c += 0.5;
  d = a;
  while(a<=c){
    ans += b;
    a += d;
  }
  cout << ans << endl;
}