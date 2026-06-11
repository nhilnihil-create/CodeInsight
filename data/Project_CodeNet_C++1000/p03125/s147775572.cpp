#include <iostream>
using namespace std;

int main(void) {
  int a,b;
  cin>>a>>b;
  if(b%a==0) cout<<a+b<<"\n";
  else cout<<b-a<<"\n";
  return 0;
}
