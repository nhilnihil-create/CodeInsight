#include <iostream>
#include <string>

using namespace std;
using ll = long long;

#define ALL(x) begin(x), end(x)
#define REP(i, n) for (size_t i = 0, i##_len = (n); i < i##_len; ++i)

int main() {
  string S;
  cin >> S;
  int mae = stoi(S.substr(0,2));
  int ato = stoi(S.substr(2,2));

  bool mmyy = false, yymm = false;
  if (mae > 0 && mae <= 12) {
    mmyy = true;
  }
  if (ato > 0 && ato <= 12) {
    yymm = true;
  }
  
  if (mmyy&&yymm) {
    cout << "AMBIGUOUS" << endl;
  } else if (mmyy) {
    cout << "MMYY" << endl;
  } else if (yymm) {
    cout << "YYMM" << endl;
  } else {
    cout << "NA" << endl;
  }
  return 0;
}
