#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using P = pair<ll,ll>;
#define REP(i, n) for (ll i = 0; i < (int)(n); i++)
#define RREP(i, n) for (ll i = (int)(n)-1; i > -1 ; i--)
#define IN(T, x) T x;cin >> x;
#define AIN(T, a, n) vector<T> a(n);REP(i, n){cin >> a[i];}
#define A2IN(T1, a, T2, b, n) vector<T1> a(n);vector<T2> b(n);REP(i, n){cin >> a[i] >> b[i];}
#define ALL(a) (a).begin(),(a).end()
#define SORT(a) sort(ALL(a))
#define RSORT(a) SORT(a);reverse(ALL(a))
template<class T>bool chmax(T &a,const T &b){if(a<b){a=b;return 1;}return 0;}
template<class T>bool chmin(T &a,const T &b){if(b<a){a=b;return 1;}return 0;}
#define OUT(x) cout << x << endl
#define BOUT(b) if(b){OUT("Yes");}else{OUT("No");}
const ll INF = 100000007;

int main() {
  IN(ll, N);
  IN(ll, M);
  ll time = M*1900 + (N-M)*100;
  ll P = pow(2, M);
  OUT(P*time);
}



