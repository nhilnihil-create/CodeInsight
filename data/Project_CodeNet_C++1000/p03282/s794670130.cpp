#include <iostream>
#include <vector>
using namespace std;
int main(){
  string s;
  cin >> s;
  int k , one;
  cin >> k;
  char ans = '1';
  for (int i = 0 ; i < s.size() ; i ++) {
    if (s.at(i) != '1') {
      ans = s.at(i);
      break;
    }
    one ++;
  }
  if (one >= k) {
    cout << 1 << endl;
  } else {
    cout << ans << endl;
  }
}