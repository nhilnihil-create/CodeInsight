#include <bits/stdc++.h>
using namespace std;
using Graph = vector<vector<int>>;

int main() {
  string S;
  cin >> S;

  int A = stoi(S.substr(0, 2));
  int B = stoi(S.substr(2, 2));

  if (A > 0 && A <= 12 && B > 0 && B <= 12)
    cout << "AMBIGUOUS" << endl;
  else if (A > 0 && A <= 12)
    cout << "MMYY" << endl;
  else if (B > 0 && B <= 12)
    cout << "YYMM" << endl;
  else
    cout << "NA" << endl;
}