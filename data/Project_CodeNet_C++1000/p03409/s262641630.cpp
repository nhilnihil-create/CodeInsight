#include <bits/stdc++.h>
using namespace std;
typedef long long  ll;
#define FOR(i,a,n) for(ll i=(ll)a;i<(ll)n;i++)
#define RFOR(i,a,n) for(ll i=(ll)n-1;i >= (ll)a;i--)
#define rep(i,n) FOR(i,0,n)
#define rrep(i,n) RFOR(i,0,n)
#define ALL(v) v.begin(), v.end()
#define bra(first,second) '(' << first << ',' << second << ')'
ll MOD = 1000000007;
ll INF = 214748364700000000;
long double EPS = 1e-11;
long double PI = 3.141592653589793238;
template<typename T>
void remove(std::vector<T>& vector, unsigned int index){
    vector.erase(vector.begin() + index);
}

using Graph = vector<vector<pair<ll,ll>>>;

bool frag[110];

int main(){
   ll N;cin >> N;
   vector<pair<ll,ll>> R(N),B(N);
   rep(i,N) cin >> R[i].second >> R[i].first;
   rep(i,N) cin >> B[i].first >> B[i].second;
   sort(ALL(R));reverse(ALL(R));
   sort(ALL(B));
   ll ans = 0;
   rep(i,N){
       rep(j,N){
           if(frag[j]) continue;
           if(B[i].first <= R[j].second || B[i].second <= R[j].first) continue;
           frag[j] = 1;
           ans++;
           break;
       }
   }
   cout << ans << endl;
}
