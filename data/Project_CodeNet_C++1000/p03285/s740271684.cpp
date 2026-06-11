#include <bits/stdc++.h>
using namespace std;
 
int main(){
  int n; cin >> n;
  bool ans = false;
  for(int i = 0; i <=25; ++i){
   for(int j = 0; j <=14; ++j){
    int x = (4*i) + (7*j);
    if(x == n){
        ans = true;
        break;
    }
   }
  }
  cout << (ans ? "Yes":"No") << '\n';
}