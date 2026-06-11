#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main(void){
  int apple,pie;
  cin >> apple >> pie;
  int ans = floor((apple*3+pie)/2);
  cout << ans << endl;
  return 0;
}