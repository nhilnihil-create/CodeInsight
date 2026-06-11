#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
int main() {
int n, Es = 0, Ws = 0;
string s;
cin>>n;
cin>>s;
  for(int i = 0; i < (int) s.size(); i++) {
    if(s[i]=='E') Es++;
    if(s[i]=='W') Ws++;
  }
int res = n;
int cE = 0, cW = 0;
  for (int i = 0; i < (int) s.size(); i++) {
    int c = cW + Es - cE;
    if (s[i]=='E') c--;
    res = min(res, c);
    if (s[i] == 'E') cE++;
    if(s[i]=='W') cW++;
  }

  cout << res << endl;
  return 0;
}