#include<bits/stdc++.h>
#define rep(i,f,n) for(ll i=(f); (i) < (n); i++)
#define repe(i,f,n) for(ll i=(f); (i) <= (n); i++)
using namespace std;
using ll = long long;
#define MOD (ll)1000000007
#define PI 3.14159265359
#define P pair<ll, ll>
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
  map<int, int> m;
  set<int> oder;
  rep(i, 0, N){
    int tmp; cin >> tmp;
    m[tmp] += 1;
    oder.insert(tmp);
  }
  ll ans = 0;

  for(auto x: m){
    if(x.first > x.second){
      ans += x.second;
    } else {
      ans += x.second - x.first;
    }
  }
  cout << ans << endl;
}
