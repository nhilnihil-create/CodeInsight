#include <bits/stdc++.h>
#define F first
#define S second
using namespace std;
using ll = long long;
typedef pair<int, int> P;
ll Mod = 1000000007;
int main() {
  string S;
  cin >> S;
  string S1 = S.substr(0,2);
  string S2 = S.substr(2,2);
  int s1 = atoi(S1.c_str());
  int s2 = atoi(S2.c_str());
  if (1 <= s1 && s1 <= 12 && 1 <= s2 && s2 <= 12) {
    cout << "AMBIGUOUS" << endl;
  } else if ((1 > s1 || s1 > 12) && (1 > s2 || s2 > 12)) {
    cout << "NA" << endl;
  } else if (1 <= s1 && s1 <= 12) {
    cout << "MMYY" << endl;
  } else {
    cout << "YYMM" << endl;
  }
  return 0;
}