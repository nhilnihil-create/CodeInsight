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
  int N, D, X;
  cin >> N >> D >> X;
  int ans = 0;
  D--;
  for(int i = 0; i < N; i++){
    int A;
    cin >> A;
    ans++;
    ans += D / A;
  }
  cout << ans + X <<endl;
}
