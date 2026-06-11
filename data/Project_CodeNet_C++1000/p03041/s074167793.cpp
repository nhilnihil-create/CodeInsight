#include <bits/stdc++.h>
using namespace std;

int main() {
  int n,k;
  string s;
  cin >> n >> k >> s;
  k--;
  if (s[k] == 'A'){
    s[k] = 'a';
  }
  else if (s[k] == 'B'){
    s[k] = 'b';
  }
  else{
    s[k] = 'c';
  }
  
  cout << s << endl;
}