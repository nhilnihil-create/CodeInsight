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
  vector<double> x(n);
  vector<string> u(n);
  double ans=0;
  for(ll i=0;i<n;i++) {
    cin >> x[i] >> u[i];
    if(u[i]=="JPY") {
      ans+=x[i];
    }
    else {
      ans+=x[i]*380000;
    }
  }
  cout << fixed << setprecision(10) << ans << endl;
}