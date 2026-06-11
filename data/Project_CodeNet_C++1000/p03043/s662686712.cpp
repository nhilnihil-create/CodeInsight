#include <bits/stdc++.h>
using namespace std;

const int MOD = 1000000007;
const int INF = 1e9;

int main(){
  double n,k;
  const int max_n = 1e5;
  cin >> n >> k;

  double ans = 0;
  double prob;
  int a;
  int cnt = 0;
  for(int i = 1; i <= n; i++){
    a = i;
    cnt = 0;
    while(a < k){
      a *= 2;
      cnt ++;
    }
    // prob = 1 / (1 << cnt);
    prob = 1 << cnt;
    ans += 1/prob;
    // cout << 1/prob << endl;
  }
  cout << fixed << setprecision(10) << ans / n << endl;


  return 0;
}