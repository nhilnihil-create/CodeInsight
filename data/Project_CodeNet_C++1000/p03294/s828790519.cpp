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
  vector<int> a(N);
  for(int i = 0; i < N; i++) cin >> a[i];
  int ans = 0;
  for(int i = 0; i < N; i++){
    ans += a[i] -1;
  }
  cout << ans <<endl;
}