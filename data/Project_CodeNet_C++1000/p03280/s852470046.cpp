#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(int)(n);i++)
using namespace std;

using ll = long long;

const int INF = 1001001001;
const ll INF_LL = 1001001001001001001LL;

int main(void){
  int a,b; cin >> a >> b;
  int ans = a*b;
  ans--;
  ans-=a-1;
  ans-=b-1;
  cout << ans << endl;
  
  return 0;
}
