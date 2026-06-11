#include <bits/stdc++.h>
#define rep(i,x,n) for(int i=x; i<(int)(n); i++)
#define rep_eq(i,x,n) for(int i=x; i<=(int)(n); i++)
using namespace std;

using ll=int64_t;

int main() {
  ll X,Y; cin >>X >>Y;
  int ans=0;
  ll i=1;
  while (true) {
    ll temp=X*pow(2,i-1);
    if (Y<temp) {
      cout <<ans <<endl;
      return 0;
    }
    ans++;
    i++;
  }
}
