#include <iostream>
 
using namespace std;
 
inline int f(int n){
  if(n % 2 == 0) return n / 2;
  else return 3 * n + 1;
}
 
int main(){
  int s, count = 1, twice = 2;
  cin >> s;
  // 特殊ケース
  if(s == 1 || s == 2 || s == 4)
  {
    count = 4;
    twice = 0;
  }
  // 4が二回出たら終了
  while(twice)
  {
    s = f(s);
    count++;
    if (s == 4) twice--;
  }
  cout << count;
}