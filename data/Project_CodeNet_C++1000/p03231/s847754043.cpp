#include<iostream>
using namespace std;

int calc_gcd(int a, int b){
  int x = max(a, b), y = min(a, b);
  if(y == 0){
    return x;
  }
  return calc_gcd(y, x % y);
}

int main(){
  int N, M;
  cin >> N >> M;

  string S, T;
  cin >> S;
  cin >> T;

  int gcd = calc_gcd(N, M);
  long long ans = static_cast<long long>(N) * M / gcd;

  bool valid = true;
  for(long long i = 0; i < N; i++){
    if(i * M % N == 0 && S[i] != T[i * M / N]){
      valid = false;
    }
  }

  if(valid){
    cout << ans << endl;
  }else{
    cout << -1 << endl;
  }
}
