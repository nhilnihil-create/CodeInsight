#include <bits/stdc++.h>

#include <fstream>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout << setprecision(20) << fixed;
  /*
  ifstream in("input.txt");
  cin.rdbuf(in.rdbuf());
  //*/
  string S;
  cin >> S;
  int minn = 99999999;
  for(int i = 0; i < S.size()-2; i++){
    int x = stoi(S.substr(i, 3));
    minn = min(minn, abs(x - 753));
  }
  cout << minn <<endl;
}
