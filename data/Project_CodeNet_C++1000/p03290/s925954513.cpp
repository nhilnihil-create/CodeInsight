#include <bits/stdc++.h>
using namespace std;

int solve(int i, int point, vector<int> &P, vector<int> &C, int memo){
  if (point <= 0) return 0;
  if (i == P.size()){
    if ((memo + 1) * 100 * (P.at(memo) - 1) < point) return 1000000;
    else if ((point / 100) % (memo + 1) == 0) return (point / 100) / (memo + 1);
    else return ((point / 100) / (memo + 1)) + 1;
  }
  
  int nothing = solve(i + 1, point, P, C, i);
  int perfect = P.at(i)
    + solve(i + 1, point - C.at(i) - (i + 1) * 100 * P.at(i), P, C, memo);
  
  /*
  cout << "i:" << i << endl;
  cout << "point:" << point << endl;
  cout << "memo:" << memo << endl;
  cout << "nothing:" << nothing << endl;
  cout << "perfect:" << perfect << endl;
  */
  
  return min(nothing, perfect);
}

int main() {
  int D, G;
  cin >> D >> G;
  vector<int> p(D);
  vector<int> c(D);
  for (int i = 0; i < D; i++) cin >> p.at(i) >> c.at(i);
  
  cout << solve(0, G, p, c, -1) << endl;
}