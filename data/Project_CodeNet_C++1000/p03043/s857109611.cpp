#include <iostream>
#include <vector>
using namespace std;
int main(){
  double N;
  long long K;
  cin >> N >> K;
  double ans = 0;
  int n = (int) (N + 1e-9);
  for(int i = 1; i < n + 1; i++){
    long long a = i;
    double b = 1 / N;
    while(a < K){
      a *= 2;
      b *= 0.5;
    }
    ans += b;
  }
  printf("%.10lf\n", ans);
}