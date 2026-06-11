#include <bits/stdc++.h>
using namespace std;
int main(){
  int N, M;
  cin >> N >> M;
  vector<int> A(N);
  for (int i = 0; i < N; i++){
    cin >> A[i];
  }
  vector<int> S(N + 1, 0);
  for (int i = 0; i < N; i++){
    S[i + 1] = (S[i] + A[i]) % M;
  }
  map<int, int> cnt;
  long long ans = 0;
  for (int i = 0; i <= N; i++){
    ans += cnt[S[i]];
    cnt[S[i]]++;
  }
  cout << ans << endl;
}