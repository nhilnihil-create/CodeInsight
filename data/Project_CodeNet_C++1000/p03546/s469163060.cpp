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
  ll n,m;
  cin >> n >> m;

//———————ワーシャルフロイド—————————————————————————————————

  vector<vector<ll>> dist(10,vector<ll>(10,1000000000000000000));
  rep(i,10){
    rep(j,10){
      cin>>dist[i][j];
    }
  }

  rep(i,10){
    rep(j,10){
      rep(k,10){
        dist[j][k]=min(dist[j][k],dist[j][i]+dist[i][k]);
      }
    }
  }

  ll ans=0;
  rep(i,n){
    rep(j,m){
      int x;
      cin>>x;
      if(x==-1) continue;
      else ans+=dist[x][1];
    }
  }

  cout << ans << endl;
}
