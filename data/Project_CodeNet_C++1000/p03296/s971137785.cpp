#include <iostream>
#include <vector>
using namespace std;

int main() {
  int n;
  cin >> n;
  vector<int> slimes(n, 0);
  
  int ans = 0;
  cin >> slimes[0];
  for (int i = 1; i < n; i++) {
    cin >> slimes[i];
    if (slimes[i] == slimes[i - 1]) {
      slimes[i] -= 1000000;
      ans++;
    }
  }
  
  cout << ans;
  return 0;
}