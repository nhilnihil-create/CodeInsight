#include <bits/stdc++.h>
using namespace std;

int main() {
  int n,a,temp;
  int ans = 30;
  cin >> n;
  for (int i=0; i<n; i++) {
    cin >> a;
    temp = 0;
    while (a%2==0) {
      temp += 1;
      a /= 2;
    }
    if(temp<ans) {
      ans = temp;
    }
  }
  cout << ans << endl;
}