#include <bits/stdc++.h>
#define rep(i,N) for (int i = 0; i < (N); ++i)
#define all(v) v.begin(), v.end()
using namespace std;
using ll = long long;
using P = pair<int, int>;
const int inf{int(1e9)};
int main(void){
  int N, K;
  cin >> N >> K;
  double ans = 0.0;
   for (int i = 1; i <= N; i++){
     double tmp = 1.0 / N;
     int now = i;
     while (now < K){
       now *= 2;
       tmp /= 2;
     }
     ans += tmp;
   }
   cout << fixed << setprecision(10) << ans << endl;
  return 0;
}
