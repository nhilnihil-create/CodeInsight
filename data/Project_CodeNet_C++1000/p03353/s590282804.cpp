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
  string S;
  int K;
  cin >> S >> K;
  set<string> SS;
  REP(i, S.size()) {
    REP(j, 5) {
      string T = "";
      REP(k, j+1) {
        if (i+k < S.size()) {
          T += S[i+k];  
        }
      }
      SS.insert(T);
    }
  }
 set<string>:: iterator it = SS.begin();
 advance(it, K-1);
 cout << *it << endl;

  return 0;
}