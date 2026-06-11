#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll MOD = 1000000007;
const ll INF = 1061109567;
const double EPS = 1e-10;

ll gcd(ll a, ll b) {
    if (b == 0) return a;
    else return gcd(b, a % b);
}

int main(){
  ll n,x;
  cin>>n>>x;
  ll X[n];
  
  for(int i=0;i<n;i++){
    cin>>X[i];
  }
  if(n==1){
    cout<<abs(X[0]-x)<<endl;
    return 0;
  }
  ll ans=gcd((ll)abs(X[0]-x),(ll)abs(X[1]-x));
  for(int i=2;i<n;i++){
    ans=gcd(ans,(ll)abs(X[i]-x));
  }
  cout<<ans<<endl;
  return 0;
}