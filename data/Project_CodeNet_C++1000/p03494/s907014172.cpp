#include<iostream>
#include<vector>
using namespace std;

int main() {
  int N;
  cin >> N;
  vector<int> v(N);
  for(auto& e: v) cin >> e;
  
  int ans = 1e9;
  for(auto e: v) {
    int cnt = 0;
    while(e%2==0) {
      e /= 2;
      cnt++;
    }
    ans = min(ans, cnt);
  }
      
  cout << ans << endl;
}