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
  int a, b, c, d;
  cin >> a >> b >> c >> d;
  if((abs(a - b) <= d && abs(b - c) <= d) || abs(a - c) <= d){
    cout << "Yes" <<endl;
  } else{
    cout << "No" <<endl;
  }
}