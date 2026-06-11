#include<bits/stdc++.h>
using namespace std;

int main(){
  string s;
  cin >> s;
  
  int zero = 0;
  int ichi = 0;
  
  for(int i = 0;i < s.size();i ++){
    if(s[i] == '0')zero ++;
    else ichi ++;
  }
  
  cout << min(zero,ichi) * 2 << endl;
}
