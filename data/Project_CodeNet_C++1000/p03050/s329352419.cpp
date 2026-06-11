#include<bits/stdc++.h>
#define all(x) (x).begin(),(x).end()
#define ll long long
#define rep(i,n) for(int i = 0; i < int(n); i++)
#define vi vector<int>
using namespace std;
const int INF = 1001001001;
const int MOD = 1e9+7;
const int dx[] = {-1, 0, 1, 0};
const int dy[] = {0, 1, 0, -1};
template<class T> inline bool chmax(T &a, const T &b){ if(a<b) { a=b; return 1; } return 0; }
template<class T> inline bool chmin(T &a, const T &b){ if(b<a) { a=b; return 1; } return 0; }

inline vector<ll> divisor(ll n){
	vector<ll> res;
	for(ll i = 1; i*i <= n; i++){
		if(n % i == 0){
      res.push_back(i);
      if(i != n/i) res.push_back(n/i);
		}
	}
  sort(all(res));
	return res;
}

int main(){
  cin.tie(0), ios::sync_with_stdio(false);
  ll n; cin >> n;
  ll ans = 0;
  auto res = divisor(n);
  for(auto x : res){
    if(x == 1) continue;
    if(n/x == n%(x-1)) ans += x-1;
  }
  cout << ans;
  cout << "\n";
  return 0;
}
