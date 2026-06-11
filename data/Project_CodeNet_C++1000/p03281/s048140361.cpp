#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(int)(n);i++)
using namespace std;

using ll = long long;

const int INF = 1001001001;
const ll INF_LL = 1001001001001001001LL;

int main(void){
  int n; cin >> n;

  int ans=0;
  for(int i = 1;i<=n;i+=2){
    int cnt = 0;
    for(int j = 1;j<=i;j++){
      if(i%j==0) cnt++;
    }
    if(cnt==8) ans++;
  }

  cout << ans << endl;
  
  return 0;
}
