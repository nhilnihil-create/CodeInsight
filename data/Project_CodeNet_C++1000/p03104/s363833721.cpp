#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define pb push_back
#define all(v) (v).begin(),(v).end()
#define fi first
#define se second
#define sz(x) ((int)(x).size())
using ll=long long;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
#define MOD  1000000007
const ll INF=1e18;
template<class T>void show(vector<T>v){for (int i = 0; i < v.size(); i++){cerr<<v[i]<<" ";}cerr<<endl;}
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b){ a = b; return 1; } return 0; }

ll f(ll x) {
     switch (x % 4) {
         case 0:
             return x;
         case 1:
             return 1;
         case 2:
             return x + 1;
         case 3:
             return 0;
     }
     return 0;
}

int main(int argc, char const *argv[]) {
  ll a, b;
  cin >> a >> b;
  if (a != 0) a--;
  ll ans = f(a) ^ f(b);
  cout << ans << endl;
  return 0;
}