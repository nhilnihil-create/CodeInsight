#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vec;
typedef vector<vec> mat;
typedef pair<ll,ll> pll;
const ll mod=1e9+7;
//const ll mod=998244353;
const ll inf=5e18;

int main() {
  ll n;
  cin >> n;
  vec a(n);
  for(ll i=0;i<n;i++) cin >> a[i];
  set<ll> al;
  sort(a.rbegin(),a.rend());
  map<ll,ll> count;
  ll ans=0;
  for(int aa:a){
    if(count.count(aa)&&count[aa]>0)count[aa]--,ans++;
    else count[(1<<(32-__builtin_clz(aa)))-aa]++;
  }
  cout << ans << endl;
}