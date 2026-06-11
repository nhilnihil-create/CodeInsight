#include <bits/stdc++.h>
#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, n) for(int i = n; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i < n; i++)
#define INF 2e9
#define ALL(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
int main()
{
  string S, T;
  cin >> S >> T;
  vector<int> seq(26, -1);
  vector<int> vec(26, -1);
  REP(i, S.size()) {
    int a = S[i] - 'a';
    int b = T[i] - 'a';
    if (vec[b] > -1 && vec[b] != a) {
      cout << "No" << endl;
      return 0;
    }
    if (seq[a] > -1 && seq[a] != b) {
      cout << "No" << endl;
      return 0;
    }

    seq[a] = b;
    vec[b] = a;
  }
  cout << "Yes" << endl;
  return 0;
}