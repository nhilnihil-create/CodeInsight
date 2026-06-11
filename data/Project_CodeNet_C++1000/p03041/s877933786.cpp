#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using ld = long double;
#define ALL(x) x.begin(),x.end()
#define P pair<int,int>
#define MOD 1000000007

int main()
{
  int n, k;
  string s;
  cin >> n >> k >> s;
  s[k - 1] += 'a' - 'A';

  cout << s << endl;

  return 0;
}
