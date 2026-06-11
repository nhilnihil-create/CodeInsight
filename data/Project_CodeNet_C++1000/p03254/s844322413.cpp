#include <bits/stdc++.h>
using namespace std;

int main() {
  int people, amount; cin >> people >> amount;
  
  vector<int> wants(people);
  
  for(int i = 0; i < people; i++) {
    cin >> wants.at(i);
  }
  std::stable_sort(wants.begin(), wants.end());
  
  int ans = 0;
  for(int i = 0; i < people; i++) {
    int current = wants.at(i);
    if(i == (people-1) && current != amount) {
      break;
    }
    
    if(amount >= current) {
      amount -= current;
      ans++;
    } else {
      break;
    }
  } 
  cout << ans << endl;
  
  return 0;
}