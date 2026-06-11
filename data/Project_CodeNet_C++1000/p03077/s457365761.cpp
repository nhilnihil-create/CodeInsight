#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n) for(int i=0;i<n;++i)

int main() {
 ll n; cin >> n;
 vector<ll> a(5);
 rep(i,5) cin >> a[i];
 sort(a.begin(),a.end());
 ll ans=5+n/a[0];
 if(n%a[0]!=0) cout << ans << endl;
 else cout << ans-1 <<endl;

}
