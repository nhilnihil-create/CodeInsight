#include <bits/stdc++.h>
#include <vector>
#define rep(i, n) for(int i = 0; i < n; ++i)
#define ll long long
using namespace std;

int main() {
  string s;
  cin >> s;
  rep(i, (int)s.size()) if(s[i]=='/') s.erase(i, 1);
  
  int num = stoi(s);
  
  if(num <= 20190430) cout << "Heisei" << endl;
  else cout << "TBD" << endl;
  
  
  
  
  return 0;
}
