#include <bits/stdc++.h>

using namespace std;
#define _overload3(_1,_2,_3,name,...) name
#define _rep(i,n) repi(i,0,n)
#define repi(i,a,b) for(int i=int(a);i<int(b);++i)
#define rep(...) _overload3(__VA_ARGS__,repi,_rep,)(__VA_ARGS__)

typedef long long ll;
typedef pair<ll, ll> P;
const ll INF = 1LL<<60;

ll gcd(ll a, ll b) {
  if(b == 0) return a;
  return gcd(b, a % b);
}

template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }

ll modpow(ll a, ll n, ll mod) {
  ll res = 1;
  while (n > 0) {
    if (n & 1) res = res * a % mod;
    a = a * a % mod;
    n >>= 1;
  }
  return res;
}


int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);

  int n, k;
  cin >> n >> k;

  vector<pair<ll, int>> sushi(n);
  rep(i, n){
    int t;
    ll d;
    cin >> t >> d;
    sushi[i] = make_pair(d, t);
  }

  sort(sushi.rbegin(), sushi.rend());

  map<int, int> mp;
  auto c = [](pair<ll, int> a, pair<ll, int> b){return a.first > b.first;};
  priority_queue<pair<ll, int>, vector<pair<ll, int>>, decltype(c)> que(c);
  ll point = 0;
  rep(i, k){
    point += sushi[i].first;
    que.push(sushi[i]);
    mp[sushi[i].second]++;
  }

  point += (mp.size() * mp.size());

  ll V = mp.size();

  ll ans = point;
  rep(i, k, n){
    
    ll val = sushi[i].first;
    ll t   = sushi[i].second;

    if(mp[t] > 0) continue;
    
    while(mp[que.top().second]==1){
      if(que.empty()) break;
      que.pop();
    }

    if(que.empty()) break;

    auto p = que.top();
    mp[p.second]--;
    que.pop();

    point -= p.first;
    point += val;
    point += 2*V + 1;
    V++;
    chmax(ans, point);

    mp[t]++;
    que.push(sushi[i]);

  }

  cout << ans << endl;





  return 0;
}
