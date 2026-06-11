#include <bits/stdc++.h>
using namespace std;
  
int main() {
  int N,M;
  cin >> N >> M;
  
  vector<long long>A(N);
  for (int i = 0; i < N; i++) {
    cin >> A.at(i);
  }
  sort(A.begin(), A.end());
  
  vector<pair<long long, int>> a(M);
  for (int i = 0; i < M; i++) {
    cin >> a.at(i).second >> a.at(i).first;
  }
  sort(a.begin(), a.end());
  reverse(a.begin(), a.end());
  
  vector<long long>B(N);
  int L = 0;
  for (int i = 0; i < M; i++) {
    if (L >= N){
        break;
    }
    for (int j = 0; j < a.at(i).second; j++) {
      B.at(L) = a.at(i).first;
      L++;
      if (L >= N){
        break;
      }
    }
  }
  
  long long sum = 0;
  for (int i = 0; i < N; i++) {
    A.at(i) = max(B.at(i),A.at(i));
    sum += A.at(i);
  }
  cout << sum << endl;
}
  
  
    