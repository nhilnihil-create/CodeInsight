#include <bits/stdc++.h>
using namespace std;;
#define rep(i, n) for(int i = 0;i < n;i++)
#define repr(i, n) for(int i = n;i >= 0;i--)
#define FOR(i, m, n) for(int i = m;i < n;i++)
#define FORR(i, m, n) for(int i = m;i >= n;i--)
#define INF 1<<30
#define LINF 1LL<<62
#define all(x) (x).begin(), (x).end()
#define F first
#define S second
#define mp make_pair
#define pb push_back
const int MOD = 1000000007;
 
typedef long long ll;
typedef vector<ll> vl;
typedef pair<ll, ll> P;
typedef pair<ll, P> PP;


int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  ll n;cin >> n;
  vector<PP> v;
  set<ll> s;
  rep(i,n){
    ll a,b;cin >>a  >> b;
    v.push_back(mp(a,mp(b,1)));
  }
  rep(i,n){
    ll a,b;cin >>a  >> b;
    v.push_back(mp(a,mp(b,0)));
  }
  sort(all(v));
  ll ans = 0;
  rep(i,2*n){
    auto tmp = v[i];
    if(v[i].second.second){
      s.insert(v[i].second.first);
    }else{
      auto it = s.lower_bound(v[i].second.first);
      if(it!=s.begin()){
        ans++;
        s.erase(--it);
      }
    }
  }
  cout << ans << endl;
}

