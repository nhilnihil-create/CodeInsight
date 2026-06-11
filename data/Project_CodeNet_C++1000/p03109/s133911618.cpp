#include <iostream>
#include <string>
#include <cmath>
#define rep(i, n) for(int i = 0; i < n; i++)
#define rep2(i, s, n) for(int i = s; i < n; i++)
using namespace std;

int main(){
  string s;
  cin >> s;
  int y = 0, m = 0, d = 0;
  rep(i, 4) y += (s[i] - '0') * pow(10, 3-i);
  rep(i, 2) m += (s[i+5] - '0') * pow(10, 1-i);
  if (y < 2019) cout << "Heisei" << endl;
  else if (y > 2019) cout << "TBD" << endl;
  else{
    if (m <= 4) cout << "Heisei" << endl;
    else cout << "TBD" << endl;
  }
  return 0;
}