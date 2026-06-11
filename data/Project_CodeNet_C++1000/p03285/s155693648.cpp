#include <bits/stdc++.h>
using namespace std;

int main(){
  int n; cin >> n;
  bool ok = false;
  for(int i = 0; i < 30; i++){
    for(int j = 0; j < 20; j++){
      if(4 * i + 7 * j == n) ok = true;
    }
  }
  if(ok) cout << "Yes" << endl;
  else cout << "No" << endl;
}
      