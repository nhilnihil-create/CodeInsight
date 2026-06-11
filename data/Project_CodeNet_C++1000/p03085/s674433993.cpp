#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
  char b;
  cin >> b;
  char ans;
  if (b == 'A')
  {
    ans = 'T';
  } else if (b == 'C') {
    ans = 'G';
  } else if (b == 'T') {
    ans = 'A';
  } else {
    ans = 'C';
  }
  cout << ans << endl;
  return 0;
}
