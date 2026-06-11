#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
  int N;
  cin >> N;
  vector <int> h(N);
  int maxh = 0;
  for (int i = 0; i < N; ++i) {
    cin >> h[i];
    maxh = max(maxh, h[i]);
  }
  
  int ans = 0;
  for (int i = 0; i < maxh; ++i) {
    bool watering = false;
    for (int j = 0; j < N; ++j) {
      if (h[j] > 0) {
        watering = true;
        h[j]--;
      } else {
        if (watering) {
          ans++;
        }
        watering = false;
      }
    }
    if (watering) {
      ans++;
    }
  }
  
  cout << ans << endl;
  return 0;
}