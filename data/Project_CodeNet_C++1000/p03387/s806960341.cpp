#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(int)(n);i++)
using namespace std;

using ll = long long;

const int INF = 1001001001;
const ll INF_LL = 1001001001001001001LL;

int main(void){
  int a,b,c; cin >> a >> b >> c;
  int M = max(max(a,b),c);
  int S = a+b+c;
    
  int x = S%2==3*M%2 ? M:M+1;
  int ans = 3*x-S;
  ans /= 2;

  cout << ans << endl;
  
  return 0;
}
