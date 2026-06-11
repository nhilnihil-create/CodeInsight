#include <bits/stdc++.h>
#define rep(i,n)for(long long i=0;i<(n);i++)
using namespace std;
typedef long long ll;
const int MOD=1e9+7;
ll gcd(ll a, ll b){
  if(b==0) return a;
  else gcd(b,a%b);
}
ll lcm(ll a, ll b){
  return a/gcd(a,b)*b;
}
int main(){
  int n,h,w;
  cin >> n >> h >> w;
  int ans=(n-h+1)*(n-w+1);
  cout << ans<< endl;
  
  return 0;
}
