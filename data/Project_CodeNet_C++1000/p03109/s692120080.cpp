#include <iostream>
#include <string>

using namespace std;

int main() {
  string s; cin >> s;
  s.erase(4, 1); s.erase(6, 1);
  int n = stoi(s);
  if(n <= 20190430) cout << "Heisei" << endl;
  else cout << "TBD" << endl;
  
  return 0;
}