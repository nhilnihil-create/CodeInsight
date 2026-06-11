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
  vector<int> L(N);
  for(int i = 0; i < N; i++) cin >> L[i];
  sort(L.begin(), L.end());
  int sum = 0;
  for(int i = 0; i < N-1; i++) sum += L[i];
  if(sum > L[N-1]) cout << "Yes" <<endl;
  else cout << "No" <<endl;
}
