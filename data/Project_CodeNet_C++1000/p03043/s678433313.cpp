#include <bits/stdc++.h>
using namespace std;

int main(void){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int N, K;
  cin >> N >> K;

  double ret = 0;

  for(int i = 1; i <= N; i++){
    double tmp = 1.0 / N;
    int now = i;
    while(now < K){
      now *= 2;
      tmp /= 2;
    }
    ret += tmp;
  }

  cout << setprecision(12) << ret << endl;

  return 0;
}
