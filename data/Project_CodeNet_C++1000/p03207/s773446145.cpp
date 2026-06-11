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
  vector<int> p(N);
  for(int i = 0; i < N; i++) cin >> p[i]; 
  sort(p.begin(), p.end());
  int ans = 0;
  for(int i = 0; i < N-1; i++){
    ans += p[i];
  }
  cout << ans + p[N-1] / 2 <<endl;
}
