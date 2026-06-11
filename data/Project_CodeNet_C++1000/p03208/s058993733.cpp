#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>
#define rep(i, n) for(int i = 0; i < n; i++)
using namespace std;

int main(){
  int n, k;
  cin >> n >> k;
  vector<int> h(n);
  rep(i, n) cin >> h[i];
  sort(h.begin(), h.end());
  int ans = 1000000000;
  rep(i, n-k+1){
    ans = min(ans, h[i+k-1] - h[i]);
  }
  cout << ans << endl;
  
  return 0;
}