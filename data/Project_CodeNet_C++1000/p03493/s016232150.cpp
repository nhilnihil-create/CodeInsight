#include <bits/stdc++.h>
using namespace std;

 
int main() {
  // 科目の数Nを受け取る
  string s;
  cin >> s;
  
  int sum = 0;
  
  for (int i = 0; i < s.size() ; i++){
  
    if(s.at(i) == '1'){
      sum += 1;
      }
  }
  cout << sum << endl;

}