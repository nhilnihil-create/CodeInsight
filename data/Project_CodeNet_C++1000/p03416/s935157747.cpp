#include <bits/stdc++.h>
using namespace std;

int main() {
  int A, B, count = 0;
  cin >> A >> B;

  for (int i = A; i <= B; i++) {
    string org, inv;
    org = std::to_string(i);
    
    for (int j = (int)org.size(); j > 0; j--) {
      if ((int)inv.size() == 0 && org[j-1] == 0) {
        continue;
      }
      inv += org[j-1];
    }
    
    if (inv==org) {
      count += 1;
    }
  }
  cout << count;
}
