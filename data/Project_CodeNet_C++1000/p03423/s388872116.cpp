#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(){
  int n;
  cin >> n;
  if (n < 3) cout << "0" << endl;
  else cout << (int)n/3 << endl;
  return 0;
}
