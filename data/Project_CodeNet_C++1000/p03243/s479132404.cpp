#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(int)(n);i++)
using namespace std;

using ll = long long;

const int INF = 1001001001;
const ll INF_LL = 1001001001001001001LL;

int main(void){
  int n; cin >> n;
  int t100=n/100,t10=(n/10)%10,t1=n-t100*100-t10*10;

  int ans;
  if(t100<t10){
    t100++;
    t10 = t100;
    t1 = t10;
  }
  else if(t100 == t10){
    if(t10<t1){
      t100++;
      t10=t100;
      t1=t100;      
    }
    else{
      t1 = t10;
    }
  }
  else{
    t10 = t100;
    t1 = t100;
  }

  ans = t1+t10*10+t100*100;
  cout << ans << endl;
  
  return 0;
}
