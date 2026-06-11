#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  ll n;
  cin>>n;
  ll res=-1;
  for (ll i=1; i*i<=n; i++) {
    res=max(res,i*i);
  }
  cout<<res<<endl;
}
