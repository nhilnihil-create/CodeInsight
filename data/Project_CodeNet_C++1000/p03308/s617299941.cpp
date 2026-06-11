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
  int N;
  cin >> N;
  vector<int> vec(N);
  for(int i = 0; i < N; i++) cin >> vec[i];
  sort(vec.begin(), vec.end());
  cout << vec[N-1] - vec[0] <<endl;
}