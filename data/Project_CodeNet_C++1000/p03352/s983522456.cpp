#include <bits/stdc++.h>
using namespace std;
int main(){
  int x;
  cin >> x;
  int ans = 1;
  for(int i=2; i<=x; i++) {
    for(int j=2; j<11; j++) {
      if(pow(i,j) > x) {
        break;
      } else if(pow(i,j) <= x && pow(i,j) > ans) {
        ans = pow(i,j);
      }
    }
  }
  cout << ans << endl;
}