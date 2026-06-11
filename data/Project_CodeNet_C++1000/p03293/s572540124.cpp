#include <bits/stdc++.h>
using namespace std;

int main(){
  string a, b;
  cin >> a >> b;
  if(a == b){puts("Yes"); return 0;}
  int len = (int)a.length();
  for(int i = 0; i < len;++i){
    char last = a[len - 1];
    string temp = a.substr(0,len - 1);
    a = last + temp;
    if(a == b){
      puts("Yes");
      return 0;
    }
  }
  if(a == b) puts("Yes");
  else puts("No");
}