#include <bits/stdc++.h>
using namespace std;

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  
  int m, k;
  cin >> m >> k;
  
  if(m == 0){
    if(k == 0){
      cout << "0 0\n";
      return 0;
    }
    else{
      cout << "-1\n";
      return 0;
    }
  }
  
  if(m == 1){
    if(k == 0){
      cout << "0 0 1 1\n";
      return 0;
    }
    else{
      cout << "-1\n";
      return 0;
    }
  }
  
  if(k >= pow(2, m)){
    cout << "-1\n";
    return 0;
  }
  
  for(int i = 0; i < pow(2, m); i++){
    if(i != k) cout << i << " ";
  }
  cout << k << " ";
  for(int i = pow(2, m) - 1; i >= 0; i--){
    if(i != k) cout << i << " ";
  }
  cout << k << '\n';
}