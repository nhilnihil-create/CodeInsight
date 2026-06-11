#include <bits/stdc++.h>
#define rep(i,N) for (int i = 0; i < (N); ++i)
#define all(v) v.begin(), v.end()
using namespace std;
using ll = long long;
using P = pair<int, int>;
const int inf{int(1e9)};
int main(void){
  int N;
  cin >> N;

  int ans = 0;
  for (int i = 1; i <= N; i+= 2){
    int num_of_divisors = 0;
    for (int j = 1; j <= i; j++){
      if (i % j == 0) num_of_divisors ++;
    }
    if (num_of_divisors == 8) ans ++;
  }
  cout << ans << endl;
}
