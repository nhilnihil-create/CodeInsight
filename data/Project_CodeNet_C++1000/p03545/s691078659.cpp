#include <bits/stdc++.h>
using namespace std;
int main(){
  string s;
  cin >> s;
  for(int bit=0; bit<(1<<3); ++bit){
    int sum = s[0]-'0';
    for(int i=1; i<=3; ++i){
      if(bit & (1<<(i-1))) sum += s[i]-'0';
      else sum -= s[i]-'0';
    }
    if(sum == 7){
      cout << s[0];
      for(int i=1; i<=3; ++i){
        if(bit & (1<<(i-1))) cout << "+" << s[i];
        else cout << "-" << s[i];
      }
      cout << "=7" << endl;
      return 0;
    }
  }
}