#include <bits/stdc++.h>
using namespace std;
using ll = long long;
typedef vector<int> vec1;
typedef vector<string> vec2;
typedef vector<double> vec3;

int main() {
  
  int x;
  cin >> x;
  int ans = 0;
  for(int i = 1; i < 1000; i++) {
    for(int j = 2; j < 1000; j++) {
      int a = pow(i,j);
      if(a > x) {
        break;
      } else {
        ans = max(ans,a);
      }
    }
  }
  cout << ans << endl;
}