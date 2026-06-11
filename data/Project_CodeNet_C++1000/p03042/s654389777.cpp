#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;
int main() {
  int s;
  cin >> s;
  int y, m;
  y = s/100;
  m = s%100;
  if(0 < y && y <13 && 0 < m && m <13) cout << "AMBIGUOUS" << endl;
  else if (0 < y && y <13) cout << "MMYY" << endl;
  else if (0 < m && m <13) cout << "YYMM" << endl;
  else cout << "NA" << endl;
}
