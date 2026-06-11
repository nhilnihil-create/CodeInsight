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
  int A, B, C, D;
  cin >> A >> B >> C >> D;
  cout << min(A, B) + min(C, D) <<endl;
}
