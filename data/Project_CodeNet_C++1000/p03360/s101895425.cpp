#include <iostream>
#include <algorithm>
using namespace std;
int main(){
  int a,b,c,k;
  cin >> a >> b >> c >> k;
  int i;
  int x =  max({a,b,c});
  for(i=0;i<k;i++){
    x *= 2;
  }
  cout << a+b+c+x-max({a,b,c}) << "\n";
  return 0;
}