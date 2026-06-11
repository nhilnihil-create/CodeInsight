#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<ll>;
using vii = vector<vi>;
using Pll = pair<ll, ll>;
#define rep(i,n) for(ll i=0;i<(ll)(n);i++)
#define all(v) v.begin(), v.end()
#define sz(x) ((int) x.size())
#define pb push_back
#define mp make_pair
#define mt make_tuple
#define F first
#define S second
const int MOD = 1e9+7;
const int INF = 2e9;
template<class T> void print(const T& t){ cout << t << endl; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
int gcd(int a,int b){return b?gcd(b,a%b):a;}

int main(){
  ll n;
  cin >> n;
  vi a(n);
  rep(i,n){
      cin >> a[i];
  }
  sort(all(a));
  while (a[1] != INF){
      for (ll i = 1; i < n;i++){
          if(a[i]==INF)continue;
          a[i] -= a[0] * (a[i] / a[0]);
          if(a[i]==0)a[i] = INF;
      }
      sort(all(a));
  }
  print(a[0]);
}