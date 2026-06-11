#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)

int main() {
  bool a= false,b = false,c = false;
  string s;
  cin >> s;
  rep(i,3){
    if(s[i] == 'a') a = true;
    if(s[i] == 'b') b = true;
    if(s[i] == 'c') c = true;
  }
  if(a&&b&&c) cout << "Yes" << endl;
  else cout << "No" << endl;
}