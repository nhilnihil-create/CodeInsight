#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int N;
  cin >> N;
  
  vector<int> mochi(N);
  for (int n = 0; n < N; n++) {
    cin >> mochi.at(n);
  }
  
  sort(mochi.begin(), mochi.end());
  reverse(mochi.begin(), mochi.end());
  
  int count = 1;
  int under = mochi.at(0);
  for (int n = 1; n < N; n++) {
    if (under > mochi.at(n)) {
      under = mochi.at(n);
      count++;
    }
  }
  
  cout << count << endl;
}
