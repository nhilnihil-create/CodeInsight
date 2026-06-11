#include <iostream>
using namespace std;

int main(){
  string s;
  int w;
  cin >> s >> w;
  string ans = "";
  for(size_t i = 0; i < s.length(); i += w){
    ans += s[i];
  }
  cout << ans << endl;
}
