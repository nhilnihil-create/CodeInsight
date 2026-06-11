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
  cin>>s;
  int n=s.size();

  queue<int> q;
  bool tobi=false;
  rep(i,n){
    if(tobi){
      tobi=false;
      continue;
    }
    if(s[i]=='A') q.push(3);
    if(s[i]=='B') {
      if(i+1<n && s[i+1]=='C') {
        q.push(2);
        tobi=true;
      }
      else q.push(0);
    }
    if(s[i]=='C') q.push(0);
  }
  
  ll ans=0;
  vector<int> p={};
  while(!q.empty()){
    int x=q.front();
    q.pop();
    if(x==0){
      if(p.empty()) continue;
      else{
        int m=p.size();
        ll moto=0;
        rep(i,m){
          if(p[i]==2) moto+=i;
        }
        sort(all(p));
        ll ato=0;
        rep(i,m){
          if(p[i]==2) ato+=i;
        }
        ans+=moto-ato;
        vector<int> r={};
        swap(p,r);
      }
    }
    else{
      p.pb(x);
    }
  }

  if(!p.empty()){
      int m=p.size();
      ll moto=0;
      rep(i,m){
        if(p[i]==2) moto+=i;
      }
      sort(all(p));
      ll ato=0;
      rep(i,m){
        if(p[i]==2) ato+=i;
      }
    ans+=moto-ato;
  }
  cout << ans << endl;
}