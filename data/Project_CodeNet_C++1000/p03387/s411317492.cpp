#include <bits/stdc++.h>
using namespace std;

int main() {
  
  vector<int> vec(3);
  
  for (int i = 0; i < 3; i++) cin >> vec[i];
  
  sort(vec.begin(), vec.end());
  
  int minNum = vec[0]; int midNum = vec[1]; int maxNum = vec[2];
  
  int difSum = (maxNum - midNum) + (maxNum - minNum);
  
  if (difSum % 2 == 0) cout << difSum / 2 << endl;
  
  else cout << difSum / 2 + 2 << endl;
  
}