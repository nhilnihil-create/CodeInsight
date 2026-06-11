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
  int R;
  cin >> R;
  if(R < 1200){
    cout << "ABC" <<endl;
  } else if(R < 2800){
    cout << "ARC" <<endl;
  } else{
    cout << "AGC" <<endl;
  }
}