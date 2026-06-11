#include "bits/stdc++.h"

using namespace std;
typedef long long ll;
#define rep(i,j,n) for (ll i = j; i < (n); i++)
#define CLR(mat,f) memset(mat, f, sizeof(mat))
#define IN(a, b, x) (a<=x&&x<b)
#define out(ans) cout << ans << endl
typedef pair<ll,ll>P;
const ll mod=1e9+7;
const int INF = 1000000;
const double PI=3.14159265359;

int main(){

  int n;cin>>n;
  int a[n+10];rep(i,0,n)cin>>a[i];

  int seq=1;
  int ans=0;
  rep(i,0,n-1){
    if(a[i]==a[i+1])seq++;
    else{
      ans+=seq/2;
      seq=1;
    }
  }
  if(seq!=1)ans+=seq/2;

  out(ans);

  return 0;
}
