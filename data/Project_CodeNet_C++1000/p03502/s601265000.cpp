#include <iostream>
using namespace std;
int main(){
  int a,b,ans=0;
  cin >> a;
  b = a;
  while(a>0){
    ans += a%10;
    a /= 10;
  }
  if(b%ans==0)cout << "Yes";
  else cout << "No";
}