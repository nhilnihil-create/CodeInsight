#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout << setprecision(20) << fixed;
  string S;
  cin >> S;
  string m = {S[5],  S[6]};
  int month = stoi(m);
  string d = {S[8],  S[9]};
  int day = stoi(d);
  if((month == 4 && day == 31)||month > 4){
    cout << "TBD" <<endl;
  } else{
    cout << "Heisei" <<endl;
  }
}