#include <bits/stdc++.h>
using namespace std;

int main(){
  string s;
  cin >> s;
  
  int num = 0;
  for(int i=0; i < s.size(); i++){
    if(s[i] == '+') num++;
    if(s[i] == '-') num--;
  }
  cout << num << endl;
}
