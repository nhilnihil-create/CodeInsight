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
  int N, M, C;
  cin >> N >> M >> C;
  vector<int> B(M);
  int sum = 0;
  int ans = 0;
  for(int i = 0; i < M; i++) cin >> B[i];
  for(int i = 0; i < N; i++){
    sum = 0;
    for(int j = 0; j < M; j++){
      int A;
      cin >> A;
      sum += B[j] * A;
    }
    sum += C;
    if(sum > 0){
      ans ++;
    }
  }
  cout << ans <<endl;
}
