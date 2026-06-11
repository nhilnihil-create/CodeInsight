#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;


int main(void){
  int a,b,c;
  
  cin >> a >> b >> c;
  
  if ((c-a)*(c-b)<0) cout << "Yes" << endl;
  else cout << "No" << endl;
  
  return 0;
}