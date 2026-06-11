#include <bits/stdc++.h>
using namespace std;

int main(){
  string s;
  int n;
  
  n = 7;
  cin >> s;

  if(s[0]=='o'){n++;}
  if(s[1]=='o'){n++;}
  if(s[2]=='o'){n++;}

  cout << n * 100 << endl;
}