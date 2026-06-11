#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

template<typename T>
void out(T x) { cout << x << endl; exit(0); }
#define watch(x) cout << (#x) << " is " << (x) << endl

const int maxn = 1e6 + 5;

ll n, k;

ll ans;

int main() {
  ios_base::sync_with_stdio(false); cin.tie(0);  cout.tie(0);

  cin>>n>>k;

  if (k==0) {
    ans=n*n;
    out(ans);
  }
  
  for (ll b=k+1; b<=n; b++) {
    ll cur = 0;
    for (ll a=k; a<=n; a+=b) {
      ll ub = min(n, ((a+b-1)/b)*b - 1);
      cur += (ub-a+1);
    }
    ans += cur;
  }

  cout<<ans<<endl;
  

  return 0;
}
