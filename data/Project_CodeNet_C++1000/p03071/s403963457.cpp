#include <iostream>
#include <algorithm>
using namespace std;
int main(){
  int a,b;
  cin >> a >> b;
  int cnt = 0;
  cnt += max(a,b);
  if(a>b) a--;
  else b--;
  cnt += max(a,b);
  cout << cnt << "\n";
  return 0;
}