#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(),(x).end()
#define m0(x) memset(x,0,sizeof(x))
const ll INF = 1001001001;
const ll MOD = 1e9 + 7;

int main(){
  map<ll, ll> mp;
  ll n, m;
  cin >> n >> m;
  rep(i, n){
    ll a;
    cin >> a;
    mp[-a]++;
  }
  rep(i, m){
    ll b, c;
    cin >> c >> b;
    mp[-b] += c;
  }
  ll ans = 0;
  for(pair<ll, ll> x : mp){
    n -= x.second;
    if(n < 0){
      ans -= x.first * (x.second + n);
      break;
    }else{
      ans -= x.first * x.second;
    }
  }
  cout << ans <<endl;
}
    