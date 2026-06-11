#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < n; i++)
#define repr(i, n) for(int i = n; i >= 0; i--)
#define INF 2e9
#define ALL(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
int main()
{
  string s;
  cin >> s;
  int n = s.size();
  int x = 753;
  rep(i, n-2) {
    int temp = (s[i] - '0') * 100 + (s[i+1] - '0') * 10 + (s[i+2] - '0');
    x = min(x, abs(temp - 753));
  }
  cout << x << endl;
  return 0;
}