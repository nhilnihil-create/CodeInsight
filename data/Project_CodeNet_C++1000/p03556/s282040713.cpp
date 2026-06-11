#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>

using namespace std;

int main() {
  long long n;
  cin >> n;
  float half = sqrt((float)n);
  int ans = 0;
  for(int i = 0; i <= half; i++)  {
    if(i*i <= n) {
      ans = max(ans,i);
    }
  }
  cout << ans*ans << endl;
  return 0;
}