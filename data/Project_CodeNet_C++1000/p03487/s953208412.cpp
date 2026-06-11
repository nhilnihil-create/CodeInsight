#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  
  map<int, int> Map;
  
  for (int i = 0; i < N; i++) {
    int x;
    cin >> x;
    
    Map[x]++;
  }
  
  int ans = 0;
  for (auto x : Map) {
    if (x.first > x.second) {
      ans += x.second;
    } else {
      ans += x.second - x.first;
    }
  }
  
  cout << ans << endl;


}