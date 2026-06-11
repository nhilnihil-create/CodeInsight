#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < n; i++)
#define repr(i, n) for(int i = n; i >= 0; i--)
#define INF 2e9
#define ALL(v) v.begin(), v.end()
using namespace std;
typedef long long ll;

bool is_mm(string s) {
  return s > "00" && s < "13";
}

int main()
{
  string s;
  cin >> s;
  string first, second;
  first += s[0];
  first += s[1];
  second += s[2];
  second += s[3];
  if (is_mm(first) && is_mm(second)) {
    cout << "AMBIGUOUS" << endl;
    return 0;
  } else {
    if (is_mm(first)) {
      cout << "MMYY" << endl;
      return 0;
    } else if (is_mm(second)) {
      cout << "YYMM" << endl;
      return 0;
    } else {
      cout << "NA" << endl;
      return 0;
    }

  }
  return 0;
}