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
  int N, M;
  cin >> N >> M;
  vector<int> A(M);
  for(int i = 0; i < N; i++){
    int k;
    cin >> k;
    for(int j = 0; j < k; j++){
      int a;
      cin >> a;
      a--;
      A[a]++;
    }
  }
  int ans = 0;
  for(int i = 0; i < M; i++) if(A[i] == N) ans++;
  cout << ans <<endl;
}
