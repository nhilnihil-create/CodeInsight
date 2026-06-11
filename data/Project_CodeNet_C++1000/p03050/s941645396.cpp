#include <bits/stdc++.h>
using namespace std;

int main(){
  int64_t N; cin >> N;

  int64_t ans = 0;
  for(int64_t x=1; x*x<=N; x++){
    if(N % x == 0){
      int64_t m = N/x-1, m2 = x-1;
      if(m > x) ans += m;
      if(m2 > x) ans += m2;
      if(m == m2 && m > x) ans -= m;
    }
  }

  cout << ans << endl;
}