#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
  int n, m, d;
  cin >> n >> m >> d;
  ll cnt = 0;
  for(int i=1; i<=n; ++i){
    if(d == 0){ ++cnt; continue;}
    if(i-d >=1) ++cnt;
    if(i+d <=n) ++cnt;
  }
  cnt *= m-1;
  double ans = (double)cnt /n /n;
  printf("%.10f", ans);
}