#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
using namespace std;
int main()
{
  string S;
  cin >> S;
  int ans = 1000;
  for (int i = 0; i < S.length()-2; i++) {
    int substr = ((int)S[i]-(int)'0')*100 + ((int)S[i+1]-(int)'0')*10 + ((int)S[i+2]-(int)'0')*1;
    int diff = abs(substr-753);
    ans = min(ans, diff);
  }
  cout << ans << endl;
  return 0;
}
