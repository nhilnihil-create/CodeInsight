#include <bits/stdc++.h>
using namespace std;

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  
  string s;
  cin >> s;
  
  if(s.size() == 2) cout << s << '\n';
  else{
    reverse(s.begin(), s.end());
    cout << s << '\n';
  }
}