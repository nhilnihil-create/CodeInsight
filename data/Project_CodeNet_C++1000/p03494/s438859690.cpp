#include <bits/stdc++.h>
using namespace std;

int main(){
  int n;
  cin >> n;
  int a[210];
  for (int i = 0; i < n; i++) cin >> a[i];
  int count = 0;
  while(true){
    bool is_odd =false;
    for (int i = 0; i < n; i++){
      if(a[i]%2 != 0){
        is_odd =true;    
      }
    }
    if(is_odd) break;
    for (int i = 0; i < n; i++){
      a[i] /= 2;
    }
    ++count;
  }
  cout << count << endl;
}