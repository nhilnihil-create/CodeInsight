#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(int)(n);i++)
using namespace std;

using ll = long long;

const int INF = 1001001001;
const ll INF_LL = 1001001001001001001LL;

int main(void){
  int a,b; cin >> a >> b;

  int ans = 0;
  if(a-b>=2){
    ans+=a;
    a--;
    ans+=a;
  }
  else if(a-b==0 || abs(a-b)==1){
    ans = a+b;
  }
  else if(b-a>=2){
    ans += b;
    b--;
    ans+=b;
  }
  cout << ans << endl;
  
  return 0;
}
