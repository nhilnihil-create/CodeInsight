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
  int A, B;
  cin >> A >> B;
  if(A == 2 || B == 2){
    cout << "No" <<endl;
  } else{
    cout << "Yes" <<endl;
  }
}
