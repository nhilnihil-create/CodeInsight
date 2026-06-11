#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, M;
  cin >> N >> M;
  vector<int> A(M);
  for(int i = 0; i < M; i++) cin >> A.at(i);
  sort(A.begin(), A.end());
  
  if(N >= M) cout << 0 << endl;
  else{
    vector<int> B(M - 1);
    for(int i = 0; i < M - 1; i++) B.at(i) = A.at(i + 1) - A.at(i);
    sort(B.begin(), B.end());
    int x = M - 1 - (N - 1);//足さないといけない数
    int ans = 0;
    for(int i = 0; i < x; i++) ans += B.at(i);
    cout << ans << endl;
  }
}