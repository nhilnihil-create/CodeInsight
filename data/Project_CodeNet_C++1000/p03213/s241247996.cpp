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
template<class T>bool chmax(T &a, const T &b) { 
  if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) {
  if (b<a) { a=b; return 1; } return 0; }
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
  int n;
  cin>>n;

  vector<int> sosu={2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97};
  vector<int> p(25);
  rep(i,25){
    int m=n;
    int cnt=0;
    while(m>0){
      cnt+=m/sosu[i];
      m/=sosu[i];
    }
    p[i]=cnt;
  }

  int nayo=0;
  int niyo=0;
  int juyo=0;
  int yo=0;
  int ni=0;
  rep(i,25){
    if(p[i]>=74) nayo++;
    if(p[i]>=24) niyo++;
    if(p[i]>=14) juyo++;
    if(p[i]>=4) yo++;
    if(p[i]>=2) ni++;
  }

  int ans=0;
  ans+=nayo;
  ans+=niyo*(ni-1);
  ans+=juyo*(yo-1);
  ans+=yo*(yo-1)*(ni-2)/2;

  cout << ans << endl;

}