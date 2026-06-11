#include <algorithm>
#include <iostream>

using namespace std;
int main() {
  string S;
  cin >> S;

  cout << (count(begin(S),end(S),'x') < 8 ? "YES" : "NO") << endl;  
  return 0;
}
