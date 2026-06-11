#include <bits/stdc++.h>
using namespace std;

int main(){
  string S;
  cin >> S;
  
  long int num = 0, ans = 0;
  for (int i = 0; i < (int)(S.length()); i++){
    if (S.at(i) == 'W'){
      ans += i - num;
      num++;
    }
  }
  
  cout << ans << endl;
}