#include <bits/stdc++.h>
using namespace std;

int main(){
  
  string s;
  cin >> s;
  
  int sum = 0;
  
  for(int i = 0; i < 4; i++){
    if(s.at(i) == '+'){
      sum++;
    }else if(s.at(i) == '-'){
      sum--;
    }
  }
  
  cout << sum << endl;
}
