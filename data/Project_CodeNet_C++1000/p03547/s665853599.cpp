#include <bits/stdc++.h>
#include <vector>
#define rep(i, n) for(int i = 0; i < n; ++i)
#define ll long long
using namespace std;

int main() {
  string x, y;
  cin >> x >> y;
  
  if(x < y) cout << "<" << endl;
  else if(x > y) cout << ">" << endl;
  else cout << "=" << endl;
  
  return 0;
}
