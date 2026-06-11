#include <bits/stdc++.h>
using namespace std;
int main(){
  int X, Y, Z, K;
  cin >> X >> Y >> Z >> K;
  vector<long long> A(X);
  for (int i = 0; i < X; i++){
    cin >> A[i];
  }
  vector<long long> B(Y);
  for (int i = 0; i < Y; i++){
    cin >> B[i];
  }
  vector<long long> C(Z);
  for (int i = 0; i < Z; i++){
    cin >> C[i];
  }
  vector<long long> S1;
  for (int i = 0; i < X; i++){
    for (int j = 0; j < Y; j++){
      S1.push_back(A[i] + B[j]);
    }
  }
  sort(S1.begin(), S1.end());
  reverse(S1.begin(), S1.end());
  vector<long long> S2;
  for (int i = 0; i < min((int) S1.size(), K); i++){
    for (int j = 0; j < Z; j++){
      S2.push_back(S1[i] + C[j]);
    }
  }
  sort(S2.begin(), S2.end());
  reverse(S2.begin(), S2.end());
  for (int i = 0; i < K; i++){
    cout << S2[i] << endl;
  }
}