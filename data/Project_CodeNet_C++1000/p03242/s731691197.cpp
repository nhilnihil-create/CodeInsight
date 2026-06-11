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
  string n;
  cin >> n;
  for(int i = 0; i < 3; i++){
    if(n[i] == '1') n[i] = '9';
    else n[i] = '1';
  }
  cout << n <<endl;
}
