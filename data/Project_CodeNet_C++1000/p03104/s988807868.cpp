#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define _overload3(_1,_2,_3,name,...) name
#define _rep(i,n) repi(i,0,n)
#define repi(i,a,b) for(int i=int(a);i<int(b);++i)
#define rep(...) _overload3(__VA_ARGS__,repi,_rep,)(__VA_ARGS__)
#define VIEW(x) do {cerr << #x << ": "; for(auto i : x) cerr << i << " "; cerr << endl;} while(0)
#define ALL(x) (x).begin(),(x).end()
template<class T>bool umax(T &a, const T &b) {if(a<b){a=b;return 1;}return 0;}
template<class T>bool umin(T &a, const T &b) {if(b<a){a=b;return 1;}return 0;}

template<typename A,size_t N,typename T> void FILL(A (&array)[N],const T &val){fill((T*)array,(T*)(array+N),val);}
template<typename T> void FILL(vector<T> &v, const T &x) {fill(v.begin(), v.end(), x);}
template<typename T> void FILL(vector<vector<T>> &v, const T &x) {for(auto &i:v)fill(i.begin(), i.end(), x);}

int main() {
  ll a,b; cin >> a >> b;
  ll d = b - a;

  auto ones = [&] (ll x, ll p) {
    if(x==0) return 0LL;
    ll ones_per_cycle = p / 2;
    ll cycle = x / p;
    ll amari = x % p;
    ll nokori = max(0LL, amari - ones_per_cycle + 1);
    return cycle * ones_per_cycle + nokori;
  };
  
  ll ans = 0;
  ll p = 1;
  rep(i, 60) {
    ll bit = (1LL<<i);
    p *= 2;
    ll c = ones(b, p) - ones(a-1, p);
    if(c%2) ans += (p/2);
  }
  cout << ans << endl;
}
