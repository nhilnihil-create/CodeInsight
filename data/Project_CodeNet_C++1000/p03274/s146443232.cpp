#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define rep(i,n) for(int i = 0; i < (int)(n); i++)
#define repo(i,n) for(int i = 1; i < (int)(n); i++)
#define pb push_back
#define mp make_pair
#define np next_permutation
#define lb lower_bound
#define ub upper_bound
#define fi first
#define se second
#define all(x) (x).begin(),(x).end()
#define mod 1000000007
#define pi acos(-1.0)
const ll INF = 1LL<<61;
ll gcd(ll x, ll y) { return y ? gcd(y, x % y) : x; }
ll lcm(ll x, ll y) { return x / gcd(x, y) * y; }
ll jou(ll N, ll P){if(P==0) return 1;
  if(P%2==0){ll t = jou(N, P/2);return t*t % mod;
  }return (N * jou(N, P-1)) % mod;}  //jou(n,mod-2)で逆元
//intの最大値2147483647 ≒ 2×10^9
//long longの最大値9223372036854775807 ≒ 9×10^18
//'大文字'+=32;    で小文字に
//  cout << fixed << setprecision (20);   小数点以下2０桁まで
//実行時間制約2秒では２×10^8回くらいまで計算できる


int main() {
  ll n,k;
  cin >> n >> k;

  vector<ll> p(n);
  rep(i,n){
    cin>>p[i];
  }

  ll ans=10000000000000000;
  rep(i,n-k+1){
    if(p[i+k-1]<=0) ans=min(ans,0-p[i]);
    else if(p[i]<=0 && 0<p[i+k-1] && abs(p[i])>=abs(p[i+k-1])) {
      ans=min(ans,2*p[i+k-1]-p[i]);
    }
    else if (p[i]<=0 && 0<p[i+k-1] && abs(p[i])<abs(p[i+k-1])) {
      ans=min(ans,p[i+k-1]-2*p[i]);
    }
    else ans=min(ans,p[i+k-1]);
  }

cout << ans << endl;

}