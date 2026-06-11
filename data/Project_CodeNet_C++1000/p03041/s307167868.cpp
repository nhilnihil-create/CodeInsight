#include <bits/stdc++.h>
#include <vector>
#define rep(i, n) for(int i = 0; i < n; ++i)
#define ll long long
using namespace std;

int main() {
  int n, k;
  string s;
  cin >> n >> k >> s;
  
  char& ch = s[k-1];
  if(ch == 'A') ch = 'a';
  else if(ch == 'B') ch = 'b';
  else ch = 'c';
  
  cout << s << endl;
  
  return 0;
}
