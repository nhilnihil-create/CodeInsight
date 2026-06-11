#define _GIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define all(v) v.begin(), v.end()
using namespace std;
using ll = long long;
using P = pair<int, int>;

bool isMonth(string s) {
  if (s == "01" ||
      s == "02" ||
      s == "03" ||
      s == "04" ||
      s == "05" ||
      s == "06" ||
      s == "07" ||
      s == "08" ||
      s == "09" ||
      s == "10" ||
      s == "11" ||
      s == "12") {
    return true;
  }

  return false;
}

int main() {
  string s;
  cin >> s;

  string s1 = s.substr(0, 2);
  string s2 = s.substr(2, s.size());

  if (isMonth(s1) && isMonth(s2)) {
    cout << "AMBIGUOUS" << endl;
    return 0;
  }

  if (isMonth(s1) && !isMonth(s2)) {
    cout << "MMYY" << endl;
    return 0;
  }
  
  if (!isMonth(s1) && isMonth(s2)) {
    cout << "YYMM" << endl;
    return 0;
  }

  cout << "NA" << endl;

  return 0;
}
