#include<bits/stdc++.h>
using namespace std;
int main(){
  string s;
  cin >> s;
  
  map<char,int> memo;
  memo[ s[0] ]++;
  memo[ s[1] ]++;
  memo[ s[2] ]++;
  
  if(memo['a'] && memo['b'] && memo['c']){
    cout << "Yes" << endl;
    return 0;
  }
  
  cout << "No" << endl;
  return 0;
}