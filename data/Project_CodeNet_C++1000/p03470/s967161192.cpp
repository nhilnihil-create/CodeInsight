#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, count = 1;
  cin >> n;
  
  vector<int> vec(n);
  for (int i=0; i<n; i++) cin >> vec.at(i);
  
  sort(vec.begin(), vec.end());
  reverse(vec.begin(), vec.end());
  
  if (n > 1) {
    for (int i=1; i<n; i++) {
      if (vec.at(i) < vec.at(i-1)) count++;
    }
  }
  cout << count << endl;
}
