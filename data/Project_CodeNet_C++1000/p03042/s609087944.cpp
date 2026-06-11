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
  cin >> S;
  string yy;
  yy += S[0];
  yy += S[1];
  string mm;
  mm += S[2];
  mm += S[3];
  if (mm <= "12" && mm > "00") {
    if (yy <= "12" && yy > "00") {
      cout << "AMBIGUOUS" << endl;
    } else {
      cout << "YYMM";
    }
  } else {
    if (yy <= "12" && yy > "00") {
      cout << "MMYY";
    } else {
      cout << "NA" << endl;
    }
  }
  return 0;
}  