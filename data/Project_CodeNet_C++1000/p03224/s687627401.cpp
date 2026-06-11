#include <bits/stdc++.h>
using namespace std;
#define FOR(I,X,Y) for(long long (I)=(X);(I)<(Y);(I)++)
#define REP(I,X,Y) for(long long (I)=(Y)-1;(I)>=(X);(I)--)
#define ALL(X) (X).begin(),(X).end()
#define pb push_back
#define COUNT(V,X) upper_bound((V).begin(),(V).end(),X)-lower_bound((V).begin(),(V).end(),X)
#define debug(x) cerr<<#x<<':'<<x<<endl;
#define DEBUG(v) cerr<<#v<<':';for(auto x:v)cerr<<x<<' ';cerr<<endl;
#define INF 1000000007
#define LINF 1000000000000000007
#define EPS 1e-9
typedef long long ll;

signed main(){
  int N;
  cin >> N;
  int k;
  bool flag = 1;
  for(k = 1;k*(k-1)<=N*2;k++){
    if(k*(k-1)==N*2){
      flag = 0;
      break;
    }
  }
  if(flag){
    cout << "No\n";
    return 0;
  }
  cout << "Yes\n" << k << endl;
  int ans[k][k-1]={0};
  int n = 0;
  int yay = 1;
  while(n < k-2){
    debug(n);
    debug(yay);
    FOR(i,0,k-1-n)ans[n][n+i]=yay+i;
    FOR(i,0,k-1-n)ans[n+1+i][n]=yay+i;
    n++;
    yay+=k-n;
  }
  ans[k-2][k-2]=N;
  ans[k-1][k-2]=N;
  FOR(i,0,k){
    DEBUG(ans[i]);
  }
  FOR(i,0,k){
    cout << k-1 << ' ';
    FOR(j,0,k-2)cout << ans[i][j] << ' ';
    cout << ans[i][k-2] << endl;
  }
}