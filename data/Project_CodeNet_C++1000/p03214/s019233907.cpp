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
  double a[n+10];rep(i,0,n)cin>>a[i];

  double dif=10000;
  double sum=0;
  rep(i,0,n){
    sum+=a[i];
  }
  double avg=sum/n;

  int ans=0;
  rep(i,0,n){
    if(abs(avg-a[i])<dif){
      dif=abs(avg-a[i]);
      ans=i;
    }
  }

  out(ans);




  return 0;
}
