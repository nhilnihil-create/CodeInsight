#include <iostream>

using namespace std;

int main() {
  int n;
  
  int res = 0;
  
  cin >> n;
  
  while (n--) {
    int k;
    cin >> k;
    
    res += (k-1);
  }
  
  cout << res << endl;
  return 0;
}