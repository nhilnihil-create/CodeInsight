#include <bits/stdc++.h>
#define rep(i,n)for(long long i=0;i<(n);i++)
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
const ll INF=1e18;
const int MOD=1e9+7;
const double pi=acos(-1);


int main(){
  ll n;
  cin >> n;
  ll ans=0;
  ll b=1;
  vector<ll>vec(n);
  rep(i,n) cin >> vec[i];
  rep(i,n-1){
    if(vec[i]==vec[i+1])b++;
    else{
      ans+=b/2;
      b=1;
    }
  }
  ans+=b/2;
  cout << ans << endl;
    
}
