#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;

int main() {
  ll k,a,b;
  cin >> k >> a >> b;
  if(a+2<b) {
    if(k-a+1>0) {
      cout << a+(k-a+1)/2*(b-a)+(k+1-a)%2 << endl;
    }
    else {
      cout << k+1 << endl;
    }
  }
  else {
    cout << k+1 << endl;
  }
}