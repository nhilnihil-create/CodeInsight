#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define rep(i,n) for(int i = 0; i < n; i++)

int main() {
  int n,k;
  string s;
  cin >> n >> k >> s;
  k--;
  if (s[k] == 'A') s[k] = 'a';
  else if (s[k] == 'B') s[k] = 'b';
  else s[k] = 'c';
  cout << s << endl;
  return 0;
}