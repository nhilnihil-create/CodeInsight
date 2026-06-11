#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(int)(n);i++)
using namespace std;

using ll = long long;

const int INF = 1001001001;
const ll INF_LL = 1001001001001001001LL;

int main(void){
  int a,b,k; cin >> a >> b >> k;

  int tmp = 0;
  int ans;
  for(int i = 100;i>=1;i--){
    if(a%i==0 && b%i==0) tmp++;
    if(tmp==k){
      ans = i;
      break;
    }
  }

  cout << ans << endl;
  
  return 0;
}
