#include<bits/stdc++.h>
#define rep(i,f,n) for(ll i=(f); (i) < (n); i++)
#define repe(i,f,n) for(ll i=(f); (i) <= (n); i++)
using namespace std;
using ll = long long;
#define MOD (ll)1000000007
#define PI 3.14159265359
//#define P pair<ll, ll>
//printf("%.10f\n")
//cout << fixed << setprecision(10);
template<class T> inline bool chmax(T& a, T b){if (a < b) { a = b; return true; } return false;}
template<class T> inline bool chmin(T& a, T b){if (a > b) { a = b; return true; } return false;}
ll INF = 1e+18;
int iINF = 1e9;

int
main()
{
  int N; cin >> N;
  vector<ll> arr(N);
  rep(i, 0, N) cin >> arr[i];

  map<ll, ll> m;
  vector<ll> acum(N + 1);
  acum[0] = 0;
  m[0] += 1;
  rep(i, 0, N){
    acum[i + 1] = acum[i] + arr[i];
    m[acum[i + 1]] += 1;
  }

  ll ans = 0;
  for(auto x: m){
    ans += (x.second * (x.second - 1)) / 2;
  }

  cout << ans << endl;

}
