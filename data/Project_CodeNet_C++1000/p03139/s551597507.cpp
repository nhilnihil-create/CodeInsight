#include <iostream>
#include <algorithm>

using namespace std;

int main(void){
  int n, x, y;
  int min_ans;
  
  cin >> n >> x >> y;
  
  if(x + y - n >= 0) min_ans = x + y - n;
  else min_ans = 0;
  
  cout << min(x, y) << " " << min_ans << endl;
  
  return 0;
}