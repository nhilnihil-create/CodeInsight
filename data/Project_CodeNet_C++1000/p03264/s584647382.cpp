#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(int)(n);i++)
using namespace std;

using ll = long long;

const int INF = 1001001001;
const ll INF_LL = 1001001001001001001LL;

int main(void){
  int k; cin >> k;

  int even = k/2;
  int odd = (k+1)/2;
  int ans = even*odd;

  cout << ans << endl;
  
  return 0;
}
