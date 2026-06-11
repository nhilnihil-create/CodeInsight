#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define rep(i,n) for(int i = 0; i < n; i++)

int main() {
  int N;
  cin >> N;
  vector<ll> a(N),b(N);
  rep(i,N) cin >> a[i];
  rep(i,N) cin >> b[i];
  ll timea = 0,timeb = 0;
  rep(i,N) timea += b[i]-a[i];
  timeb = timea;
  rep(i,N) {
    if (b[i]-a[i] <= 0) timeb -= a[i]-b[i];
    else timea -= (b[i]-a[i]+1)/2;
  }
  if ((timea >= 0) && (timeb >= 0)) cout << "Yes" << endl;
  else cout << "No" << endl;
  return 0;
}
