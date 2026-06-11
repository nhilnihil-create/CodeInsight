#include <iostream>
using namespace std;
int main(){
  string s;
  cin >> s;
  int abc[3];fill(abc,abc+3,0);
  for(int i = 0; i < s.length(); ++i) ++abc[s[i]-'a'];
  int M = max({abc[0],abc[1],abc[2]}), m = min({abc[0],abc[1],abc[2]});
  if(M < m+2) cout << "YES" << endl;
  else cout << "NO" << endl;
  return 0;
}
