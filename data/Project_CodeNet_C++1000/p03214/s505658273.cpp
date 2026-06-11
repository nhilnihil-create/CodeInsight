#include <bits/stdc++.h>
using namespace std;
typedef long long  ll;
#define FOR(i,a,n) for(ll i=(ll)a;i<(ll)n;i++)
#define RFOR(i,a,n) for(ll i=(ll)n-1;i >= (ll)a;i--)
#define rep(i,n) FOR(i,0,n)
#define rrep(i,n) RFOR(i,0,n)
#define ALL(v) v.begin(), v.end()
ll MOD = 1000000007;
ll INF = 214748364700000000;
double EPS = 1e-12;
double PI = 3.141592653589793238;
template<typename T>
void remove(std::vector<T>& vector, unsigned int index){
    vector.erase(vector.begin() + index);
}

using Graph = vector<vector<ll>>;

int main(){
   double N;cin >> N;
   vector<double> A(N);
   double sum = 0,av = 0;
   rep(i,N){
       cin >> A[i];
       sum += A[i];
   }
   av = sum / N;
   vector<pair<double,ll>> D(N);
   rep(i,N){
       D[i].first = abs(A[i] - av);
       D[i].second = i;
   }
   sort(ALL(D));
   cout << D[0].second << endl;
}