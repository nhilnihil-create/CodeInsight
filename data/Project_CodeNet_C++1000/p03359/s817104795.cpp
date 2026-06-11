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
  int a, b;
  cin >> a >> b;
  if(b < a){
    cout << a - 1 <<endl;
  } else{
    cout << a <<endl;
  }
}