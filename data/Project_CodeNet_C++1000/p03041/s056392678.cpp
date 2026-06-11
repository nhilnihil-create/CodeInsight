#include <bits/stdc++.h>
#include <string>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;

int main() {
  int n, k;
  cin >> n >> k;
  string s;
  cin >> s;
  string s2;
  if(s[k-1]=='A') s2="a";
  if(s[k-1]=='B') s2="b";
  if(s[k-1]=='C') s2="c";
  s.replace(k-1,1,s2);
  cout << s << endl;

}
