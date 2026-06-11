#include<bits/stdc++.h>
using namespace std;

int main() {
  int n; cin >> n;
  bool f = false;
  for(int i = 0; i <= n/7; i++){
    for(int j = 0; j <= n/4; j++){
      if(7*i + 4*j == n) f = true;
    }
  }
  if(f) cout << "Yes" << endl;
  else cout << "No" << endl;
}