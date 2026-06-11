#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;

int main() {
  ll n,m,d;
  cin >> n >> m >> d;
  ll zero=0;
  double out=2*(n-d)*(m-1)/double(n)/double(n);
  if(d==0) {
    out/=2.0;
  }
  cout << fixed << setprecision(10) << out << endl;
}