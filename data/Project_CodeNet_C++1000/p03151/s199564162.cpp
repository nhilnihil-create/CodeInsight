#include <bits/stdc++.h>
using namespace std;
int main(){
  int N;
  cin >> N;
  vector<int> A(N);
  long long sumA = 0;
  for (int i = 0; i < N; i++){
    cin >> A[i];
    sumA += A[i];
  }
  vector<int> B(N);
  long long sumB = 0;
  for (int i = 0; i < N; i++){
    cin >> B[i];
    sumB += B[i];
  }
  if (sumA < sumB){
    cout << -1 << endl;
  } else {
    vector<int> D(N);
    for (int i = 0; i < N; i++){
      D[i] = A[i] - B[i];
    }
    sort(D.begin(), D.end());
    vector<int> D1, D2;
    for (int i = 0; i < N; i++){
      if (D[i] < 0){
        D1.push_back(D[i]);
      } else {
        D2.push_back(D[i]);
      }
    }
    int ans = D1.size();
    long long f = 0;
    for (int i = 0; i < ans; i++){
      f -= D1[i];
    }
    reverse(D2.begin(), D2.end());
    long long Dsum = 0;
    for (int i = 0; i < D2.size(); i++){
      if (Dsum >= f){
        break;
      }
      ans++;
      Dsum += D2[i];
    }
    cout << ans << endl;
  }
}