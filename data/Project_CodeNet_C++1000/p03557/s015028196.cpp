#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n) for(int i=0;i<n;++i)
#define ALL(a)  (a).begin(),(a).end()

int main() {
 int n; cin >> n;
  vector<ll> a(n),b(n),c(n);
  rep(i,n)cin >> a[i];sort(a.begin(),a.end());
  rep(i,n)cin >> b[i];sort(b.begin(),b.end());
  rep(i,n)cin >> c[i];sort(c.begin(),c.end());

 ll sum=0;

  for(int i=0;i<n;i++){
    auto itra=lower_bound(ALL(a),b[i]);
    ll ai=itra-a.begin();//b[i]より小さく、aのなかで一番大きい数のindex+1
    auto itrc=upper_bound(ALL(c),b[i]);
    ll ci=itrc-c.begin();//b[i]より大きく、Cのなかで一番小さい数のindex
    ll cii=n-ci;
    sum+=ai*cii;
  }

 cout << sum << endl;
}
