#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

typedef long long ll;
typedef pair<ll,int> P;
typedef pair<ll,P> PP;
vector<PP> r;
ll a[100005];
ll b[100005];
int main() {
  int n;
  cin >> n;
  for(int i = 0; i < n; i++) {
    cin >> a[i] >> b[i];
    r.push_back(PP(b[i]+a[i],P(a[i],i)));
  }

  sort(r.begin(),r.end());

  ll ans = 0;
  bool TorA = true;
  for(int i = n - 1; i >= 0; i--) {
    if(TorA) ans += a[r[i].second.second];
    else ans -= b[r[i].second.second];
    TorA = !TorA;
    
  }

  cout << ans << endl;
}
