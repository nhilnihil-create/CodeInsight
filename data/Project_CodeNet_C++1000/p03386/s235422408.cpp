#include <iostream>
using namespace std;
int main(){
  int a,b,k;
  cin >> a >> b >> k;
  int i;
  for(i=0;i<k;i++){
    if(a>b-k) break;
    cout << a << "\n";
    a++;
  }
  for(i=k-1;i>=0;i--){
    if(b-i<=a) i=b-a;
    cout << b-i << "\n";
  }
  return 0;
}