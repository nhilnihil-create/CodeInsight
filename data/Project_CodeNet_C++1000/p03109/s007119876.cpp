#include <iostream>
#include <cstdio>
using namespace std;

int main(){
  int y, m, d;
  
  scanf("%d/%d/%d", &y, &m, &d);
  
  int ymd = 10000*y + 100*m + d;
  if(ymd <= 20190430) cout << "Heisei" << endl;
  else cout << "TBD" << endl;
  
  return 0;
}