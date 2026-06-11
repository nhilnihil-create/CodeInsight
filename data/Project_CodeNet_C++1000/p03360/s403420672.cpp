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
  vector<int> vec(3);
  for(int i = 0; i < 3; i++) cin >> vec[i];
  int K;
  cin >> K;
  sort(vec.begin(), vec.end());
  cout << vec[0] + vec[1] + vec[2] * (int)pow(2, K) <<endl;
}