#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
#define ll long long
#define ld long double
#define rep(i,n) for(int i = 0; i < (int)(n); i++)
#define repo(i,n) for(int i = 1; i < (int)(n); i++)
#define pb push_back
#define mp make_pair
#define np next_permutation
#define fi first
#define se second
#define all(x) (x).begin(),(x).end()
#define uniq(v) v.erase(unique(v.begin(),v.end()),v.end())
#define lb(v,x) (lower_bound(v.begin(),v.end(),x)-v.begin())
#define ub(v,x) (upper_bound(v.begin(),v.end(),x)-v.begin())
using Pair = pair<ll,pair<int,int>>;
#define pq priority_queue<Pair, vector<Pair>, greater<Pair>> 
const ll mod=1000000007;
//const ll mod=998244353;
const ld pi=acos(-1.0);
const ll INF = 1LL<<61;
template<class T>bool chmax(T &a, const T &b) { 
  if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) {
  if (b<a) { a=b; return 1; } return 0; }
ll gcd(ll x, ll y) { return y ? gcd(y, x % y) : x; }
ll lcm(ll x, ll y) { return x / gcd(x, y) * y; }
//intの最大値2147483647 ≒ 2×10^9
//long longの最大値9223372036854775807 ≒ 9×10^18
//'大文字'+=32;    で小文字に
//  cout << fixed << setprecision (20);   小数点以下2０桁まで
//実行時間制約2秒では２×10^8回くらいまで計算できる




int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);

  int a,b,c,k;
  cin>>a>>b>>c>>k;

  vector<ll> p(a);
  vector<ll> q(b);
  vector<ll> r(c);
  vector<ll> s(b*c);
  rep(i,a) cin>>p[i];
  rep(i,b) cin>>q[i];
  rep(i,c) cin>>r[i];
  rep(i,b){
    rep(j,c){
      s[i*c+j]=q[i]+r[j];
    }
  }

  sort(all(p));
  sort(all(s));

//————————————————二分探索——————————————————————————

  ll ng = INF;
  ll ok = 0;
  while (abs(ok - ng) > 1) {
    ll mid = (ng + ok) / 2;

    ll cnt=0;
    rep(i,a){
      int x = lb(s,mid-p[i]);
      cnt+=b*c-x;
    }
    (cnt>=k? ok : ng) = mid;
  }

//——————————————————————————————————————————

  vector<ll> ans;
  rep(i,a){
    int x = lb(s,ok-p[i]);
    for(int j=x;j<b*c;j++){
      ans.pb(p[i]+s[j]);
    }
  }  

  sort(all(ans));
  reverse(all(ans));

  rep(i,k){
    cout << ans[i] << endl;
  }

}