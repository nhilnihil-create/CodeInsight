#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;


int main(void){
  int i,a,b,c,d;
  
  cin >> a >> b >> c >> d;
  
  if (abs(a-c)<=d || (abs(a-b)<=d && abs(b-c)<=d)) cout << "Yes" << endl;
  else cout << "No" << endl;
  
  return 0;
}