#include <bits/stdc++.h>
#define rep(i,n)for(long long i=0;i<(n);i++)
using namespace std;
typedef long long ll;
const int MOD=1e9+7;
const int MAX = 1000000;
const ll INF = (1LL << 31) - 1;
const double pi=acos(-1);

long double n,m,d,ans=0;

int main(){
  cin >> n >> m >> d;
  if(d==0){
    ans=(m-1)/n;
  }
  else{
    ans=2*(m-1)*(n-d)/pow(n,2);
  }
  cout << fixed << setprecision(10) << ans << endl;
  
}
