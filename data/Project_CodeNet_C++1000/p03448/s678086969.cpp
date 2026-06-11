#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(int)(n);i++)
using namespace std;

using ll = long long;

const int INF = 1001001001;
const ll INF_LL = 1001001001001001001LL;

int main(void){
  int a,b,c,x; cin >> a >> b >> c >> x;
  int ans = 0;

  for(int i = 0;i<=a;i++)
    for(int j = 0;j<=b;j++)
      for(int k = 0;k<=c;k++)
    if(500*i+100*j+50*k==x) ans++;

  cout << ans << endl;
  
  return 0;
}
