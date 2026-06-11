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
  int N, X;
  cin >> N >> X;
  vector<int> m(N);
  int ans = 0;
  for(int i = 0; i < N; i++){
    cin >> m[i];
    X -= m[i];
    ans++;
  }
  sort(m.begin(), m.end());
  cout << ans + X/m[0] <<endl;
}
