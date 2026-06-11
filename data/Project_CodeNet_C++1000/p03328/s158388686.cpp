#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(int)(n);i++)
using namespace std;

using ll = long long;

const int INF = 1001001001;
const ll INF_LL = 1001001001001001001LL;

int main(void){
  int a,b; cin >> a >> b;
  int n = 1000;
  vector<int> sum(n);
  sum[0] = 0;
  for(int i = 1;i<n;i++) sum[i]=sum[i-1]+i;

  int res;
  for(int i = 1;i<n;i++){
    if(sum[i]-a>0){
      if(sum[i]-a!=sum[i+1]-b) continue;
      res = sum[i]-a;
    }
  }

  cout << res << endl;
  
  return 0;
}
