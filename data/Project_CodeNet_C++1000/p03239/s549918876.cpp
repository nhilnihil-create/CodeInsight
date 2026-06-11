#include <bits/stdc++.h>

#include <fstream>
using namespace std;

#define INF 99999999

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout << setprecision(20) << fixed;
  /*
  ifstream in("input.txt");
  cin.rdbuf(in.rdbuf());
  //*/
  int N, T;
  cin >> N >> T;
  int ans = INF;
  for(int i = 0; i < N; i++){
    int c, t;
    cin >> c >> t;
    if(t <= T && c < ans){
      ans = c;
    }
  }
  if(ans == INF) cout << "TLE" <<endl;
  else cout << ans <<endl;
}
