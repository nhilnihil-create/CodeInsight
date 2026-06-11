#include<bits/stdc++.h>
#define ll long long int

using namespace std;

const ll mod=1000000007;
const ll inf=1e18;

ll gcd(ll a,ll b){
  if(a < b) return gcd(b, a);
    int r;
    while ((r=a%b)) {
    a = b;
    b = r;
  }
  return b;
}

int main(){

  ll n;
  cin >> n;
  ll a[n];
  for(int i=0;i<n;i++)cin >> a[i];

  ll dp1[n]={};//a[0]~a[i]までの最大公約数
  ll dp2[n]={};//a[i]~a[n-1]までの最大公約数

  dp1[0]=a[0];
  for(int i=1;i<n;i++)dp1[i]=gcd(dp1[i-1],a[i]);

  dp2[n-1]=a[n-1];
  for(int i=n-2;i>=0;i--)dp2[i]=gcd(dp2[i+1],a[i]);

  ll s=0;
  s=dp2[1];
  for(int i=1;i<n-1;i++){
    s=max(s,gcd(dp1[i-1],dp2[i+1]));
  }
  s=max(s,dp1[n-2]);

  cout << s << endl;

}