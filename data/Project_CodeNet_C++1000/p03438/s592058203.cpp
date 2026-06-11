#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,s,n) for(int i = s; i < (int)(n); i++)

int main() {
  int n;
  cin >> n;
  bool same = true;
  ll as = 0,bs = 0,c = 0;
  vector<ll>a(n);
  vector<ll>b(n);
  rep(i,0,n) cin >> a[i];
  rep(i,0,n) cin >> b[i];
  rep(i,0,n){
    if(a[i] != b[i]) same = false;
    if(b[i] >= a[i]) c += (b[i]-a[i]+1)/2;
    as += a[i];
    bs += b[i];
  }
  if(bs-as < c && !same) cout << "No" << endl;
  else cout << "Yes" << endl;
}