#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vec;
typedef vector<vec> mat;
typedef pair<ll,ll> pll;
const ll mod=1e9+7;
//const ll mod=998244353;
const ll inf=1LL<<61;

int main() {
  ll k,a,b;
  cin >> k >> a >> b;
  ll ans=1;
  if(k-1>=a&&a+1<b) {
    ans+=a-1;
    k-=a-1;
    ans+=k/2*(b-a);
    ans+=k%2;
  }
  else {
    ans+=k;
  }
  cout << ans << endl;
}