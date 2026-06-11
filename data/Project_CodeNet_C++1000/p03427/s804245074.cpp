#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vec;
typedef vector<vec> mat;
typedef pair<ll,ll> pll;
const ll mod=1e9+7;
//const ll mod=998244353;
const ll inf=5e18;

int main() {
  ll n;
  cin >> n;
  ll cnt=0;
  ll ans=0;
  ll temp=n;
  while(n>=10) {
    n/=10;
  }
  while(temp) {
    ans+=temp%10;
    temp/=10;
    cnt++;
  }
  ans=max(ans,n-1+(cnt-1)*9);
  cout << ans << endl; 
}