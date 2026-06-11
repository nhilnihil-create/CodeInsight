#include <bits/stdc++.h>
using namespace std;

int main() {
  string str;
  cin >> str;
  if(str.size()==2){
    cout << str;
  }
  if(str.size()==3){
    reverse(str.begin(),str.end());
    cout << str;
  }
  return 0;
}
