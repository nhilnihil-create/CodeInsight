#include <bits/stdc++.h>
#define REP(i, n) for(int i = 0; i < n; i++)
#define ALL(v) (v).begin(), (v).end()

using namespace std;
using ll = long long;

int main()
{
  string S; cin >> S;

  int k = S.size();

  if (count(ALL(S), 'o') + (15-k) >= 8) cout << "YES" << endl;
  else cout << "NO" << endl;
}