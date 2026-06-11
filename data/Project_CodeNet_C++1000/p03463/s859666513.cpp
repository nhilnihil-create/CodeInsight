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

  ll n,a,b;cin>>n>>a>>b;
  string A="Alice",B="Borys",D="Draw";
  if((b-a-1)%2==1)out(A);
  else out(B);


  return 0;
}
