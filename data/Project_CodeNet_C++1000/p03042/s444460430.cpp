#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <cmath>
#define rep(i,n) for (int i = 0; i < n; ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
  string S;
  cin >> S;
  bool l = false, r = false;
  if (S[0] == '0') {
    if (S[1] != '0') l = true;
  }
  else if (S[0] == '1') {
    if (S[1] == '0' || S[1] == '1' || S[1] == '2') l = true;
  }
  if (S[2] == '0') {
    if (S[3] != '0') r = true;
  }
  else if (S[2] == '1') {
    if (S[3] == '0' || S[3] == '1' || S[3] == '2') r = true;
  }
  if (l) {
    if (r) cout << "AMBIGUOUS" << endl;
    else cout << "MMYY" << endl;
  }
  else {
    if (r) cout << "YYMM" << endl;
    else cout << "NA" << endl;
  }
  return 0;
}