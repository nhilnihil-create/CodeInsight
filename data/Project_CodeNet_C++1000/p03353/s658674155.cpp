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
  string s;
  int k;
  cin >> s >> k;
  int n=s.size();

  vector<string> p;
  rep(i,n){
    p.pb(s.substr(i,1));
    if(i+1<n) p.pb(s.substr(i,2));
    if(i+2<n) p.pb(s.substr(i,3));
    if(i+3<n) p.pb(s.substr(i,4));
    if(i+4<n) p.pb(s.substr(i,5));
  }

  sort(all(p));

  if(k==1) {
    cout << p[0] << endl;
    return 0;
  }

  ll now=1;
  repo(i,p.size()){
    if(p[i]!=p[i-1]) now++;
    if(now==k) {
      cout << p[i] << endl;
      return 0;
    }
  }

}
