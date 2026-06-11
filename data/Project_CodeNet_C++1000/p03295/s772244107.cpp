#include <bits/stdc++.h>
using namespace std;
int main(){
  int N, M;
  cin >> N >> M;
  vector<pair<int, int>> R(M);
  for (int i = 0; i < M; i++){
    int A, B;
    cin >> A >> B;
    R[i] = make_pair(B, A);
  }
  sort(R.begin(), R.end());
  int c = 0;
  int ans = 0;
  for (int i = 0; i < M; i++){
    if (R[i].second >= c){
      c = R[i].first;
      ans++;
    }
  }
  cout << ans << endl;
}