# include <iostream>
# include <cmath>
using namespace std;

int main() {
  long long a, b, c, k;
  cin >> a >> b >> c >> k;
  
  long long ans;
  if (k % 2 == 0) ans = a - b;
  else ans = b - a;
    
  if (ans > pow(10, 18)) {
    cout << "Unfair" << endl;
    exit(0);
  }
  
  cout << ans << endl;
  
  return 0;
}