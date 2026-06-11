#include <iostream>
using namespace std;
int main(){
  string s;
  cin >> s;
  int ans = 0;
  for(const char& i : s)
    if(i == '2') ans++;
  cout << ans;
  return 0;
}