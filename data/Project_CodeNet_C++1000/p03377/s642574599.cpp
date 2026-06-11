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
  int A, B, X;
  cin >> A >> B >> X;
  if(A <= X && A + B >= X) cout << "YES" <<endl;
  else cout << "NO"<<endl;
}
