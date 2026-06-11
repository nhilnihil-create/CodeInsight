#include <bits/stdc++.h>
using namespace std;

int main() {
  vector<int64_t> vec;
  vec.push_back(2);
  vec.push_back(1);
  int x;
  
  cin >> x;
  
  for (int i = 0; i <= x; i++) {  
    if (i == 0 || i == 1) continue;
    
    vec.push_back(vec[i - 1] + vec[i - 2]);
  }
  
  cout << vec[x] << endl;
}
