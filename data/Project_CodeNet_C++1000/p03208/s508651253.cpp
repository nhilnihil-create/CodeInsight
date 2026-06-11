#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int solve(int n , int k) {
  vector<int> h(n);
  for (int i = 0; i < n ; i ++) {
    cin >> h[i];
  }
  sort(h.begin(), h.end());
  long diff = 100000000000 , tmp = 0;
  for (int i = 0 ; i < n - k + 1 ; i ++) {
    tmp = h[k + i - 1] - h[i];
    diff = min(diff , tmp);
  }
  return diff;
}

int main(){
  int n , k;
  cin >> n >> k;
  cout << solve(n , k) << endl;
}