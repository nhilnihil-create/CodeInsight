#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

int main(void) {
  
  string ans = "Yes";
  int N;
  cin >> N;
  
  vector<string> W(N);
  string w1;
  cin >> w1;
  W[0] = w1;
  
  for (int i = 0; i < N-1; i++) {
    string w;
    cin >> w;
    string wp = W[i];
    if (wp[wp.size()-1] != w[0]) {
     ans = "No";
     break;
    } else {
      for (int j = 0; j < W.size(); j++) {
        if (W[j] == w) {
          ans = "No";
          break;
        }
      }
      if (ans == "No") {
        break;
      }
    }
    W[i+1] = w;
  }
  cout << ans << endl;
  return 0;
}