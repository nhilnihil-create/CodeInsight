#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  
  int ans = 0, c = -1;
  for(int i = 0; i < n; i++){
    int k;
    cin >> k;
    if(c == k) ans++, c = -1;
    else c = k;
  }
  
  cout << ans << endl;
}