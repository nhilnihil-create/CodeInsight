#include <bits/stdc++.h>
#define rep(i,s,n) for (int i = s; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
  int n,k; string s;
  cin >> n >> k >> s;
  cout << s.substr(0,k-1);
  string t = s.substr(k-1,1);
  if (t == "A") cout << "a";
  else if (t == "B") cout << "b";
  else cout << "c";
  cout << s.substr(k,n-k) << endl;
  return 0;
}
