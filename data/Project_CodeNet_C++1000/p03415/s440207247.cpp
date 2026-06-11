#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(int)(n);i++)
using namespace std;

int main(void){
  vector<string> s(3);

  rep(i,3) cin >> s[i];

  rep(i,3) cout << s.at(i).at(i);
  cout << endl;
  
  return 0;
}
