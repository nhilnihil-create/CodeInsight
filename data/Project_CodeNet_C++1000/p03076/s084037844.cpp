#include<bits/stdc++.h>
using namespace std;

int main() {
  vector<int> dishes(5);
  for (int i = 0; i < 5; i++) cin >> dishes.at(i);
  
  int ignore_i = 0;
  for (int i = 0; i < 5; i++) {
    if (dishes.at(i)%10 == 0) continue;
    if (10-(dishes.at(ignore_i)%10) < 10-(dishes.at(i)%10)) ignore_i = i;
  }
  int ans = 0;
  for (int i = 0; i < 5; i++) {
    ans += dishes.at(i);
    if (dishes.at(i)%10 == 0) continue;
    if (ignore_i != i) {
      ans += 10-(dishes.at(i)%10);
    }
  }
  cout << ans << endl;
}