#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
using namespace std;
using ll = long long;
const double PI = 3.14159265358979323846;

int main() {
  int s;
  cin >> s;
  bool flag_1 = false;
  bool flag_2 = false;
  int div_100 = s / 100;
  int rem_100 = s % 100;
  if(1 <= div_100 && div_100 <= 12) flag_1 = true;
  if(1 <= rem_100 && rem_100 <= 12) flag_2 = true;
  
  if(flag_1) {
    if(flag_2) cout << "AMBIGUOUS" << endl;
    else cout << "MMYY" << endl;
  }
  else {
    if(flag_2) cout << "YYMM" << endl;
    else cout << "NA" << endl;
  }
  return 0;
}