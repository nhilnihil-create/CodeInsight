#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
  string s, t;
  cin >> s >> t;
  if(s[0] == t[2] && s[1] == t[1] && s[2] == t[0]) cout << "YES" << "\n";
  else cout << "NO" << "\n";
}
