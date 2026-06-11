#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef pair<int, int> p;
typedef long long ll;
int main() {
  int n, k;
  string s;
  cin >> n >> k >> s;
  k--;
  if (s[k] == 'A') s[k] = 'a';
  if (s[k] == 'B') s[k] = 'b';
  if (s[k] == 'C') s[k] = 'c';
  cout << s << endl;
  return 0;
}