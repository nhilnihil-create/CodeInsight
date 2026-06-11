#include<bits/stdc++.h>
using namespace std;

int main(){
  string s;
  cin >> s;
  int count = 0;
  if(s[0] != 'A'){
    cout << "WA" << endl;
    return 0;
  }
  for(int i = 2; i < s.size() - 1; i++){
    if(s[i] == 'C'){
      count++;
    }
  }
  if(count != 1){
    cout << "WA" << endl;
    return 0;
  }
  for(int i = 0; i < s.size(); i++){
    if(s[i] != 'A' && s[i] != 'C' && s[i] >= 65 && s[i] <= 90){
      cout << "WA" << endl;
      return 0;
    }
  }
  cout << "AC" << endl;
  return 0;
}
