#include <iostream>
#include <vector>
using namespace std;
int main(){
  int i;
  vector<char> s(10);
  for(i=0;i<9;i++) cin >> s[i];
  cout << s[0] << s[4] << s[8] << "\n";
  return 0;
}
