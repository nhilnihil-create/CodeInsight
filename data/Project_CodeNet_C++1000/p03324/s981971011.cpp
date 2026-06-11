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
  int D, N;
  cin >> D >> N;
  if(N == 100) cout << (int)(pow(100,D) * 101)<<endl;
  else cout << (int)(pow(100, D) * N) <<endl;
}