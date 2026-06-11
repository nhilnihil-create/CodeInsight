#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;

int main() {
  string s;
  cin >> s;
  while(true){
    if(s.at(0) == s.at(1) && s.at(1) == s.at(2) && s.at(2) == s.at(0)){
      cout << s << endl;
      break;
    }
    int x = stoi(s);
    x++;
    s = to_string(x);
    }
 }
