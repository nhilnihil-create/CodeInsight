#include <bits/stdc++.h>
using namespace std;

bool check(char s){
  if (s == 'A' || s == 'G' || s == 'C' || s == 'T'){
    return true;
  }
  else{
    return false;
  }
}

int main(){
  string S;
  cin >> S;
  
  int N = (int)(S.length()), ans = 0;
  
  for (int i = 0; i < N; i++){
    int num = 0;
    for (int j = i; j < N; j++){
      if (check(S.at(j)) == true){
        num++;
      }
      else{
        break;
      }
    }
    
    ans = max(ans, num);
  }
  
  cout << ans << endl;
}