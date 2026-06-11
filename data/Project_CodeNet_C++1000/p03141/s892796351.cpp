#include <bits/stdc++.h>
using namespace std;
int main(){
  int N;
  cin >> N;
  vector<int> A(N), B(N);
  for (int i = 0; i < N; i++){
    cin >> A[i] >> B[i];
  }
  vector<tuple<int, int, int>> T(N);
  for (int i = 0; i < N; i++){
    T[i] = make_tuple(A[i] + B[i], A[i], B[i]);
  }
  sort(T.begin(), T.end());
  deque<pair<int, int>> dq;
  for (int i = 0; i < N; i++){
    dq.push_back(make_pair(get<1>(T[i]), get<2>(T[i])));
  }
  long long ans = 0;
  for (int i = 0; i < N; i++){
    if (i % 2 == 0){
      ans += dq.back().first;
      dq.pop_back();
    }
    if (i % 2 == 1){
      ans -= dq.back().second;
      dq.pop_back();
    }
  }
  cout << ans << endl;
}