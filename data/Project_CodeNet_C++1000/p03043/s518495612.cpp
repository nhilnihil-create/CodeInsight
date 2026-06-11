#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
  int N,K;
  cin >> N >> K;
  double ans;
  for (int i = 1; i <= N; ++i){
    int wk = 1;
    int now = i;
    while (now < K) {
      now *= 2;
      wk *= 2;      
    }
    ans += (double)(1.0)/wk / N;     
  }
  printf("%.12f\n", ans);
  //cout << ans / N << endl;
  return 0;
}