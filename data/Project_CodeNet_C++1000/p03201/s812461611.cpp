#include <bits/stdc++.h>
using namespace std;
int main(){
  int N;
  cin >> N;
  vector<int> A(N);
  for (int i = 0; i < N; i++){
    cin >> A[i];
  }
  sort(A.begin(), A.end());
  reverse(A.begin(), A.end());
  vector<int> p;
  for (int i = 1; i <= 30; i++){
    p.push_back(1 << i);
  }
  vector<int> B(N);
  for (int i = 0; i < N; i++){
    B[i] = *upper_bound(p.begin(), p.end(), A[i]) - A[i];
  }
  set<pair<int, int>> A2;
  for (int i = 0; i < N; i++){
    A2.insert(make_pair(A[i], i));
  }
  int ans = 0;
  for (int i = 0; i < N; i++){
    if (A2.count(make_pair(A[i], i))){
      auto itr = A2.lower_bound(make_pair(B[i], 0));
      if ((*itr).first == B[i] && (*itr).second != i){
        A2.erase(itr);
        A2.erase(make_pair(A[i], i));
        ans++;
      }
    }
  }
  cout << ans << endl;
}