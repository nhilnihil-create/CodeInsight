#include<bits/stdc++.h>
using namespace std;
#define INFTY 1<<20
typedef long long int ll;
const int MOD=1000000007;
using Graph = vector<vector<int>>;
#define rep(i,n) for (int i = 0; i < (n); ++i)
ll gcd(ll a, ll b) { return b?gcd(b,a%b):a;}
ll lcm(ll a, ll b) { return a/gcd(a,b)*b;}

int main(){
  double n,m;cin>>n>>m;
  double a = 1.0-pow(0.5,m);
  double b = pow(0.5,m);
  double c = 1900.0*m + 100.0 * (n-m);
  double ans = 0.0;
  double k = 1.0;
  bool ok = true;
  while(ok){
    ans += pow(a,k-1)*b*c*k;
    k = k + 1.0;
    //cout<<k;
    if(pow(a,k-1)*b*c*k<0.001) ok = false;
  }
  int res;
  res = ans;
  cout<<res+1;
  
  return 0;
}