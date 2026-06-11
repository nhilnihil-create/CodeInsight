#include <bits/stdc++.h>
using namespace std;
typedef long long  ll;
#define FOR(i,a,n) for(ll i=(ll)a;i<(ll)n;i++)
#define RFOR(i,a,n) for(ll i=(ll)n-1;i >= (ll)a;i--)
#define rep(i,n) FOR(i,0,n)
#define rrep(i,n) RFOR(i,0,n)
#define ALL(v) v.begin(), v.end()
#define bra(first,second) '(' << first << ',' << second << ')'
//constexpr ll MOD = 1000000007;
constexpr ll MOD = 998244353;
ll INF = 6001001001001001001;
long double EPS = 1e-11;
long double PI = 3.141592653589793238;
template<typename T>
void remove(std::vector<T>& vector, unsigned int index){
    vector.erase(vector.begin() + index);
}

using Graph = vector<vector<ll>>;

int main(){
   ll N,K;
   cin >> N >> K;
   vector<pair<ll,ll>> P(N);
   rep(i,N) cin >> P[i].first >> P[i].second;
   sort(ALL(P));
   ll ans = INF;
   rep(i,N) FOR(j,i,N) FOR(k,j,N) FOR(l,k,N){
      ll x1 = min({P[i].first,P[j].first,P[k].first,P[l].first});
      ll x2 = max({P[i].first,P[j].first,P[k].first,P[l].first});
      ll y1 = min({P[i].second,P[j].second,P[k].second,P[l].second});
      ll y2 = max({P[i].second,P[j].second,P[k].second,P[l].second});
      ll cnt = 0;
      rep(j,N){
         if(x1 <= P[j].first && P[j].first <= x2 && y1 <= P[j].second && P[j].second <= y2) cnt++;
      }
      if(cnt >= K){
         if(x1 == x1 && y1 == y2) ans = min(ans,(ll)1);
         else if(x1 == x2) ans = min(ans,abs(y2-y1));
         else if(y1 == y2) ans = min(ans,abs(x2-x1));
         else ans = min(ans,abs((x2-x1)*(y2-y1)));
      }
   }
   cout << ans << endl;
}