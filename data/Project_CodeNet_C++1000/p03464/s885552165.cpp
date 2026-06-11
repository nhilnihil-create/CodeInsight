#include <bits/stdc++.h>
using namespace std;
long long INF = 1000000000000000000;
int main(){
  int K;
  cin >> K;
  vector<int> A(K);
  for (int i = 0; i < K; i++){
    cin >> A[i];
  }
  long long tv1 = INF;
  long long fv1 = 0;
  while (tv1 - fv1 > 1){
    long long mid = (tv1 + fv1) / 2;
    long long N = mid;
    for (int i = 0; i < K; i++){
      N = N / A[i] * A[i];
    }
    if (N >= 2){
      tv1 = mid;
    } else {
      fv1 = mid;
    }
  }
  long long tv2 = 0;
  long long fv2 = INF;
  while (fv2 - tv2 > 1){
    long long mid = (tv2 + fv2) / 2;
    long long N = mid;
    for (int i = 0; i < K; i++){
      N = N / A[i] * A[i];
    }
    if (N <= 2){
      tv2 = mid;
    } else {
      fv2 = mid;
    }
  }
  if (tv2 < tv1){
    cout << -1 << endl;
  } else {
    cout << tv1 << ' ' << tv2 << endl;
  }
}