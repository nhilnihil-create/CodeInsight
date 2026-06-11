#include<bits/stdc++.h>
using namespace std;

int main(){

  long long i, N, K;
  double p = 0;
  cin >> N >> K;
  
  //N:サイコロ, K:これ以上になると勝ち
  for(i=1; i<=N; i++){
    long long ex = 0;
    while(i * pow(2, ex) < K) ex++;
    p += pow(0.5, ex);
  }
  p /= N;
  printf("%.12f\n", p);
  return 0;
}